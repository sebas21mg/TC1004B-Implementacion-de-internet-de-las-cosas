// HC_SR04_ESP32

const int Trigger = 13;
const int Echo = 12;

void setup() {
Serial.begin(9600);
pinMode(Trigger, OUTPUT); //pin de salida
pinMode(Echo, INPUT); //pin de entrada
digitalWrite(Trigger, LOW); //inicializar el pin con 0
}

void loop() {
long t; //tiempo 
long d; //distancia

digitalWrite(Trigger, HIGH); 
delayMicroseconds(10); 
digitalWrite(Trigger, LOW); 

t = pulseIn(Echo, HIGH); //pulso de 10 microsegundos 
d = t/59; //escalar la distancia a cm 

Serial.println("Distancia: ");
Serial.println(d);
Serial.print(" cm"); 
Serial.println();
delay(1000); // delay de 100 ms 
}