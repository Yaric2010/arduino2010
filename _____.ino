//#include <Ultrasonic.h>
#include <OLED_I2C.h>

// Ultrasonic sonik_exe(9, 10); //trig , echo
OLED ECK(SDA, SCL);
char give_me = ' ';
byte led = 13;
int acum = A2;
int acum_data = 0;
int delae[1000];

int i2;
byte zap;

extern uint8_t SmallFont[];
extern uint8_t TinyFont[];
extern uint8_t RusFont[];
extern uint8_t MediumNumbers[];

int EXE = 0;

int enA = 3;
int in1 = 4;
int in2 = 5;

int enB = 6;
int in3 = 7;
int in4 = 8;

int f1 = A1;
int f1_D = 0;

int f2 = A0;
int f2_D = 0;
byte perfar = 12;
byte far = 10;

byte bep = 2;

int exe = 1;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(f1, INPUT);
  pinMode(f2, INPUT);
  pinMode(perfar, 1);
  pinMode(far, 1);
  pinMode(bep, OUTPUT);
  pinMode(acum, 0);

  Serial.begin(9600);

  delay(1500);
  Serial.println("Conected!");
  ECK.begin();
  ECK.setFont(RusFont);
}


void loop()
{
  
  f1_D = digitalRead(f1);
  f2_D = digitalRead(f2);
  acum_data = analogRead(acum);
  
  acum_data = (acum_data - 500) / 3;
  if(acum_data > 100)
  {
    acum_data = 100;
  }
  Serial.print("acum = %");
  Serial.println(acum_data);
  
   // EXE = sonik_exe.Ranging(CM);
  ECK.clrScr();
  ECK.print("pfhzl frrevekznjhf = ", 10, 10);
  ECK.printNumI(acum_data, 60, 30);
  ECK.print("%", 90, 30);
  ECK.update();
   // Z.setFont(RusFont);
  //  Z.print("Ktdj_L", 10, 2);
  //  Z.print("Ghfdj_L", 75, 2);
  //  Z.print("Hfnjzybt", CENTER, 35);

  //  Z.setFont(MediumNumbers);
  //  Z.printNumI(f1_D, 25, 13);
  //  Z.printNumI(f2_D, 85, 13);
   // Z.printNumI(EXE, CENTER, 47);
  //  Serial.println(f2_D);

  




  if (Serial.available())
  {
    give_me = Serial.read();
    if(zap == 1)
    {
      dalae[i2] = millis - delae[i2];
     
      zap = 0;
      i2 = i2 + 1;
    }
    switch (give_me)
    {
      case 'w':
        up();

        break;

      case '0':
        st0p();

        break;

      case 'd':
        pravo();


        break;

      case 'a':
        levo();


        break;

      case 's':
        down();

        break;
      case '8':
        pravo();
        //   delay(2000);
        levo();
        //  delay(2000);
        st0p();

        break;

      case '^':
        digitalWrite(perfar, 1);

        break;
      case '*':
        digitalWrite(perfar, 0);
        digitalWrite(far, 0);
        break;

      case '/':
        digitalWrite(far, 1);
        break;

      case '#':
        tone(bep, 800);
        break;

      case '_':
        noTone(bep);
        break;

      case '@':
        for (int i = 800; i < 2000; i = i + 1)
        {
          tone(bep, i);
          // delayMicroseconds(10);

        }
        for (int i = 2000; i > 800; i = i - 1)
        { 
          tone(bep, i);
          //  delayMicroseconds(10);

        }
        break;
     case '':
        dalae[i2] = milles;
        zap = 0;   

    }
    

  }
 





}

void up()
{
  analogWrite(enA, 255);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);

  analogWrite(enB, 230);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void down()
{
  analogWrite(enB, 255);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);

  analogWrite(enA, 230);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void levo() {
  analogWrite(enA, 255);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);

  analogWrite(enB, 255);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void pravo() {
  analogWrite(enA, 255);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);

  analogWrite(enB, 255);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void st0p() {
  analogWrite(enA, 122);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);

  analogWrite(enB, 152);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
