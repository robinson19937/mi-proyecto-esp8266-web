#include <ESP8266WiFi.h>

// Configuración de red
const char* ssid = "Familia_Lopez";
const char* password = "Antonella1980";

// Configuración IP estática (ajusta estos valores según tu red)
IPAddress local_IP(192, 168, 1, 100);   // IP que tendrá el ESP8266
IPAddress gateway(192, 168, 1, 1);      // IP de tu router
IPAddress subnet(255, 255, 255, 0);     // Máscara de subred

WiFiServer server(80);  // Servidor web en puerto 80
const int ledPin = 16;  // Pin del LED (D0 en NodeMCU)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Configurar IP estática
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("Error al configurar IP estática!");
  }

  // Conectar a WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP estática asignada: ");
  Serial.println(WiFi.localIP());

  server.begin();  // Iniciar servidor web
}

void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("Nuevo cliente conectado");
    String request = client.readStringUntil('\r');
    client.flush();

    // Control del LED
    if (request.indexOf("GET /on") != -1) {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ENCENDIDO");
    } 
    else if (request.indexOf("GET /off") != -1) {
      digitalWrite(ledPin, LOW);
      Serial.println("LED APAGADO");
    }

    // Respuesta HTTP básica
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<h1>ESP8266 Web Server</h1>");
    client.println("<p>LED: " + String(digitalRead(ledPin) ? "ON" : "OFF") + "</p>");
    
    delay(10);
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
