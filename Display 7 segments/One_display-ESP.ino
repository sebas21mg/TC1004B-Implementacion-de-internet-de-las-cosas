#define A 2
#define B 4
#define C 5
#define D 18
#define E 19
#define F 21
#define G 22

# define push_button 23

int display[] = {A, B, C, D, E, F, G};
int cnt = -1;

void print0(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void print1(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print2(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}
void print3(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}

void print4(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void print5(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void print6(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void print7(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print8(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void print9(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void printA(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void printB(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void printC(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void printD(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}

void printE(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void printF(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void printNum(int num, int display[]){
    if (num == 0)
        print0(display);
    else if (num == 1)
        print1(display);
    else if (num == 2)
        print2(display);
    else if (num == 3)
        print3(display);
    else if (num == 4)
        print4(display);
    else if (num == 5)
        print5(display);
    else if (num == 6)
        print6(display);
    else if (num == 7)
        print7(display);
    else if (num == 8)
        print8(display);
    else if (num == 9)
        print9(display);
}

void btnPushed (void)
{
    cnt = -1;
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
}

void loop(){
    cnt++;
    if (cnt == 10)
        cnt = 0;

    printNum(cnt, display);
    attachInterrupt(digitalPinToInterrupt(push_button), btnPushed, FALLING);
    delay(1000);
};