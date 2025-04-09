let btnOn, btnOff;
let statusText;

function setup() {
  createCanvas(400, 400);
  background(52, 235, 119);
  textAlign(CENTER);

  // Botón Encender
  btnOn = createButton('ENCENDER LED');
  btnOn.position(150, 180);
  btnOn.style('background-color', '#FF4444');
  btnOn.style('color', 'white');
  btnOn.mousePressed(() => sendCommand('/on'));

  // Botón Apagar
  btnOff = createButton('APAGAR LED');
  btnOff.position(150, 220);
  btnOff.style('background-color', '#FFD700');
  btnOff.style('color', 'black');
  btnOff.mousePressed(() => sendCommand('/off'));

  // Texto de estado
  statusText = createP("Estado: Esperando...");
  statusText.position(120, 260);
  statusText.style('font-size', '16px');
}

function draw() {
  // No necesario, pero se deja para estructura
}

function sendCommand(endpoint) {
  const ip = "192.168.1.100"; // ¡Asegúrate de que sea la misma IP estática!
  fetch(`http://${ip}${endpoint}`)
    .then(() => {
      statusText.html(`Estado: Comando <b>${endpoint}</b> enviado ✅`);
    })
    .catch(err => {
      statusText.html(`Error: No se pudo conectar al ESP8266 ❌`);
      console.error("Error:", err);
    });
}
