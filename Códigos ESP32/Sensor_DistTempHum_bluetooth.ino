#include "BluetoothSerial.h"
#include <DHT.h>

BluetoothSerial SerialBT;

#define DHT_sensor_type DHT11
#define DHT_sensor_pin 4 //En el ESP32 solo puede ser el pin 4
#define Trigger 5
#define Echo 18

DHT dht_sensor(4, DHT11);

void setup() {
  Serial.println("Conectando....");
  SerialBT.begin("ESP32_LABVIEWX_team5");
  
  Serial.begin(115200);
  dht_sensor.begin();
  pinMode(Trigger, OUTPUT); //pin de salida
  pinMode(Echo, INPUT); //pin de entrada
  digitalWrite(Trigger, LOW); //inicializar el pin con 0
}

void loop() {
  float humedad = dht_sensor.readHumidity();
  int t; //tiempo 
  int d; //distancia

  float temperatura = dht_sensor.readTemperature();

  if(isnan(humedad) || isnan(temperatura)){
    Serial.println("ERROR");
  }
  else{
    //Sensor de temp/humedad
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print("\tTemperatura: ");
    Serial.print(temperatura);
    Serial.println();

    SerialBT.print("Humedad: ");
    SerialBT.print(humedad);
    SerialBT.print("    Temperatura: ");
    SerialBT.print(temperatura);
    SerialBT.println();
  }
  
  //Sensor de distancia
  digitalWrite(Trigger, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(Trigger, LOW); 

  t = pulseIn(Echo, HIGH); //pulso de 10 microsegundos 
  d = t/59; //escalar la distancia a cm 
  
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print(" cm"); 
  Serial.println();Serial.println();

  SerialBT.print("Distancia: ");
  SerialBT.print(d);
  SerialBT.print(" cm"); 
  SerialBT.println();SerialBT.println();
 
  delay(1000);
}