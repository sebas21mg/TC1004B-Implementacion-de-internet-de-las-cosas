// Juego Pong usando una LCD I2C

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);

// int i = 0;
// int cantidad_letras = 12;
// int direccion = 1;

int p1_pos = 0, p2_pos = 0;
int ball_pos [2] = {0, 0};

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(7,0);
}

void printPlayers (void)
{
    lcd.setCursor(0, p1_pos);
    lcd.print("|");
    lcd.setCursor(0, p1_pos);
    
    lcd.setCursor(15, p2_pos);
    lcd.print("|");
}

void printBall (void)
{
    lcd.setCursor(ball_pos[0], ball_pos[1]);
    lcd.print("o");
}

void loop() {
    lcd.clear();
    printPlayers();

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
    lcd.print("Hola mundo");
    delay(1000);
}