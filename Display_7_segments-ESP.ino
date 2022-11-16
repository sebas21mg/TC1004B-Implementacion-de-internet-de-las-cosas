# define push_button 23

#define A 2
#define B 4
#define C 5
#define D 18
#define E 19
#define F 21
#define G 22

int display_left[] = {A, B, C, D, E, F, G};
int btn_cnt = 1;
int units = -1, tens = 0;

void imp0(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void imp1(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void imp2(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}
void imp3(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}

void imp4(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void imp5(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void imp6(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void imp7(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void imp8(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void imp9(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void impA(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void impB(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void impC(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void impD(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}

void impE(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void impF(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void imprimirNUM(int num, int display[]){
    if (num == 0)
        imp0(display);
    else if (num == 1)
        imp1(display);
    else if (num == 2)
        imp2(display);
    else if (num == 3)
        imp3(display);
    else if (num == 4)
        imp4(display);
    else if (num == 5)
        imp5(display);
    else if (num == 6)
        imp6(display);
    else if (num == 7)
        imp7(display);
    else if (num == 8)
        imp8(display);
    else if (num == 9)
        imp9(display);
}

void btnPushed (void)
{
    Serial.println(btn_cnt);
    btn_cnt++;
}

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
  
    pinMode(push_button,INPUT);
  
    Serial.begin(9600);
  
    // attachInterrupt(digitalPinToInterrupt(2), resetear, RISING);
    // attachInterrupt(digitalPinToInterrupt(3), countSerial, RISING);
}

void loop(){
    units++;
    if (units == 10)
    {
        tens++;
        units = 0;
    }
    if (tens == 10)
        tens = 0;

    imprimirNUM(units, display_left);
    attachInterrupt(digitalPinToInterrupt(push_button), btnPushed, RISING);
    delay(1000);
};