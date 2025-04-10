
El ESP8266 es un microcontrolador con Wi-Fi integrado, ideal para proyectos de IoT debido a su bajo costo y facilidad de uso. En este proyecto, el objetivo es construir una página web que envíe solicitudes HTTP a un ESP8266, el cual estará configurado para ejecutar tareas específicas, como encender luces, controlar motores o leer sensores. Este enfoque es comúnmente utilizado en proyectos de domótica o automatización.

La página web funciona como interfaz de usuario, donde el usuario puede interactuar con botones o formularios. Cada interacción genera una solicitud HTTP, que es procesada por el ESP8266. El microcontrolador responde ejecutando las tareas solicitadas y devuelve una respuesta al navegador, que puede actualizar la interfaz según los resultados.

El ESP8266 actúa como un servidor web, escuchando las solicitudes en su dirección IP local. Con el uso de librerías como ESP8266WiFi.h y ESP8266WebServer.h, se puede configurar el ESP8266 para que maneje estas solicitudes y ejecute las acciones correspondientes.
