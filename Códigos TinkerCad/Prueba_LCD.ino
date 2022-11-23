// Frase que rebota en los laterales del LCD

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16,2);

int i = 0;
int cantidad_letras = 12;
int direccion = 1;

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
}

void loop() {
    if (i + cantidad_letras == 16)
        direccion = 0;
    if (i == 0)
        direccion = 1;

    if (direccion == 1)
        i++;
    else 
        i--;

    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print("Sebas es gei");
    delay(1000);
}