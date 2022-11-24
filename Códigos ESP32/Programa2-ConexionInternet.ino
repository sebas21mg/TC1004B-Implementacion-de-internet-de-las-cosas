//Programa 2.

#include <DHT.h>
#define DHT_SENSOR_PIN 21
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(21,DHT11);


#include <WiFi.h>


WiFiServer server(80);


const char* ssid     = "";
const char* password = "";


int contconexion = 0;

String header; 

String paginaInicio = "<!DOCTYPE html>"
"<html>"
"<head>"
"<meta charset='utf-8' />"
"<META HTTP-EQUIV='Refresh' CONTENT='5'>"
"<title>ESP32</title>"
"</head>"
"<body>"
"<center>"
"<h3>Servidor Web ESP32 (IoT)</h3>";

String paginaFin = "</center>"
"</body>"
"</html>";


void setup() {
  dht_sensor.begin();
  
  Serial.begin(115200);
  Serial.println("");
  
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED and contconexion <20) { 
    ++contconexion;
    delay(500);
    Serial.print(".");
  }
  if (contconexion <20) {

      
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
      server.begin(); 
  }
  else { 
      Serial.println("");
      Serial.println("Error de conexion");
  }
}

 

void loop(){
  WiFiClient client = server.available();  

  if (client) {                            
    Serial.println("New Client.");          
    String currentLine = "";               
    while (client.connected()) {           
      if (client.available()) {            
        char c = client.read();            
        Serial.write(c);                   
        header += c;
        if (c == '\n') {                   
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
                     
            
            client.println(paginaInicio + "HUMEDAD: "+ String(dht_sensor.readHumidity()) +"%"+ "   TEMPERATURA: "+String(dht_sensor.readTemperature()) +"°C"+ paginaFin);
            
            
            
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }

    header = "";

    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}