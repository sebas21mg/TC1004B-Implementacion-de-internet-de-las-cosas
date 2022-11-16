// Declarar el nombre de los pines
# define a1 4
# define b1 5
# define c1 8
# define d1 7
# define e1 6
# define f1 3
# define g1 10

# define a2 A3
# define b2 A2
# define c2 9
# define d2 A0
# define e2 A1
# define f2 A4
# define g2 A5

# define push_button 2

int display_left[] = {a1, b1, c1, d1, e1, f1, g1};
int display_right[] = {a2, b2, c2, d2, e2, f2, g2};

int btn_cnt = 1;
int units = 0, tens = 0;
unsigned long current_time, previous_time = 0;
int waiting_time = 1000;
int btn_state = 0;

void setup()
{
    // Inicializar los pines como outputs
    pinMode(a1, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(c1, OUTPUT);
    pinMode(d1, OUTPUT);
    pinMode(e1, OUTPUT);
    pinMode(f1, OUTPUT);
    pinMode(g1, OUTPUT);

    pinMode(a2, OUTPUT);
    pinMode(b2, OUTPUT);
    pinMode(c2, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(e2, OUTPUT);
    pinMode(f2, OUTPUT);
    pinMode(g2, OUTPUT);

    pinMode(push_button, INPUT);

    Serial.begin(9600);
}

void print_0(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}

void print_1(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void print_2(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void print_3(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void print_4(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_5(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_6(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_7(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], LOW);
}

void print_8(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_9(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], LOW);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_A(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_B(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_C(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], LOW);
}

void print_D(int display[])
{
    digitalWrite(display[0], LOW);
    digitalWrite(display[1], HIGH);
    digitalWrite(display[2], HIGH);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], LOW);
    digitalWrite(display[6], HIGH);
}

void print_E(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], HIGH);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void print_F(int display[])
{
    digitalWrite(display[0], HIGH);
    digitalWrite(display[1], LOW);
    digitalWrite(display[2], LOW);
    digitalWrite(display[3], LOW);
    digitalWrite(display[4], HIGH);
    digitalWrite(display[5], HIGH);
    digitalWrite(display[6], HIGH);
}

void printNumbers(int number, int display[])
{
    if (number == 0)
        print_0(display);
    else if (number == 1)
        print_1(display);
    else if (number == 2)
        print_2(display);
    else if (number == 3)
        print_3(display);
    else if (number == 4)
        print_4(display);
    else if (number == 5)
        print_5(display);
    else if (number == 6)
        print_6(display);
    else if (number == 7)
        print_7(display);
    else if (number == 8)
        print_8(display);
    else if (number == 9)
        print_9(display);
}

// Función antirebote
void btnPushed(void)
{
    if (digitalRead(push_button) == HIGH && btn_state == 0)
    {
        Serial.println(btn_cnt);
        btn_cnt++;
        btn_state = 1;
    }
    else if (digitalRead(push_button) == LOW && btn_state == 1)
        btn_state = 0;
}

void loop()
{
    // No se usa delay, sino el tiempo de ejecución
    current_time = millis();

    if (current_time - previous_time > waiting_time){
        units++;
        previous_time = current_time;
    }

    if (units == 10)
    {
        tens++;
        units = 0;
    }
    if (tens == 10)
        tens = 0;

    printNumbers(units, display_right);
    printNumbers(tens, display_left);
    btnPushed();
}