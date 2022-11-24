//Programa 3
#include "ThingSpeak.h"
#include "WiFi.h"

#include "DHT.h"


#define pin1 5      

const char* ssid     = "Sebas' Redmi";
const char* password = "sebas2103";

unsigned long channelID = 1954217;               
const char* WriteAPIKey = "DH58SRQ7WJV63MWW";    

WiFiClient cliente;

DHT dht1(pin1, DHT11);    //El azul.


void setup() {
  Serial.begin(115200);
  Serial.println("Test de sensores:");

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi conectado!");

  ThingSpeak.begin(cliente);

  dht1.begin();
}

void loop() {

  delay(1000);
  leerdht1();


  ThingSpeak.writeFields(channelID,WriteAPIKey);
  Serial.println("Datos enviados a ThingSpeak!");
  delay(14000);
}

void leerdht1() {
  
  float t1 = dht1.readTemperature();
  float h1 = dht1.readHumidity();

  while (isnan(t1) || isnan(h1)){
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo lectura...");
    delay(1000);
    t1 = dht1.readTemperature();
    h1 = dht1.readHumidity();
  }

  Serial.print("Temperatura DHT11: ");
  Serial.print(t1);
  Serial.println(" ºC.");

  Serial.print("Humedad DHT11: ");
  Serial.print(h1);
  Serial.println(" %."); 

  Serial.println("-----------------------");

  ThingSpeak.setField (1,t1);
  ThingSpeak.setField (2,h1);
}