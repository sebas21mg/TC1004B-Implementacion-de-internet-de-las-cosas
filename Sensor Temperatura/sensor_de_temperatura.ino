//Se debe de tener la libreria "DHT sensor library"
#include <DHT.h>

#define DHT_sensor_pin 4
#define DHT_sensor_type DHT11

DHT dht_sensor(DHT_sensor_pin, DHT11); // Solo se puede trabajar sobre el pin 4 en el ESP32

void setup() {
  Serial.begin(115200);
  dht_sensor.begin();
}

void loop() {
  float humedad = dht_sensor.readHumidity();

  float temperatura = dht_sensor.readTemperature();

  if(isnan(humedad) || isnan(temperatura)){
    Serial.println("ERROR");
  }
  else{
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print("\tTemperatura: ");
    Serial.print(temperatura);
    Serial.println();

    delay(1000);
  }
}