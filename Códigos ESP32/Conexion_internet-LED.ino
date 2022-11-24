//Programa 1. 

#include <WiFi.h>

WiFiServer server(80);


const char* ssid     = "Sebas' Redmi";
const char* password = "sebas2103";

int contar = 0;

String header; // Variable para guardar el HTTP request

String estadoSalida = "off";

const int salida = 5; // Led en el pin 5

String pagina = "<!DOCTYPE html>"
"<html>"
"<head>"
"<meta charset='utf-1' />"
"<title>ESP32 TEC</title>"
"</head>"
"<body>"
"<center>"
"<h1>Servidor Web ESP32 (IOT)</h1>"
"<p><a href='/on'><button style='height:20px;width:200px'>ON</button></a></p>"
"<p><a href='/off'><button style='height:20px;width:200px'>OFF</button></a></p>"
"</center>"
"</body>"
"</html>";


void setup() {
  Serial.begin(115200);
  Serial.println("");
  
  pinMode(salida, OUTPUT); 
  digitalWrite(salida, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and contar <20) { 
    ++contar;
    delay(500);
    Serial.print(".");
  }
  if (contar <20) {
      
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
            
            if (header.indexOf("GET /on") >= 0) {
              Serial.println("GPIO on");
              estadoSalida = "on";
              digitalWrite(salida, HIGH);
            } else if (header.indexOf("GET /off") >= 0) {
              Serial.println("GPIO off");
              estadoSalida = "off";
              digitalWrite(salida, LOW);
            }
            
            client.println(pagina);
            
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