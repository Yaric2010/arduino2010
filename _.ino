#include <Ultrasonic.h>
#include <OLED_I2C.h>

Ultrasonic sonik_exe(9, 10); //trig , echo
OLED Z(SDA, SCL);
char give_me = ' '; 
byte led = 13;

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
double pin_knop = 11;
double data_knop = 0;

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
  pinMode(pin_knop, INPUT);
 // pinMode(f2, INPUT);
  pinMode(perfar, 1);
  pinMode(far, 1);
  Serial.begin(9600);
  Z.begin();
  Z.setFont(RusFont);
  Z.clrScr();
  Z.print("Ghbdtn", 5, 20);
  Z.update();
  delay(600);
  Z.print("Vjq drk.xbntkm!", 5, 30);
  Z.update();
  delay(600);
  Z.setFont(SmallFont);
  
  Z.print("(:", 5, 40);
  
  Z.update();
  delay(3000);
  Z.clrScr();
  
  
  delay(1500);
  Serial.println("Conected!");
}


void loop()
{
  
  f1_D = digitalRead(f1);
  f2_D = digitalRead(f2);/*
  EXE = sonik_exe.Ranging(CM);

  Z.setFont(RusFont);
  Z.print("Ktdj_L", 10, 2);
  Z.print("Ghfdj_L", 75, 2);
  Z.print("Hfnjzybt", CENTER, 35);

  Z.setFont(MediumNumbers);
  Z.printNumI(f1_D, 25, 13);
  Z.printNumI(f2_D, 85, 13);
  Z.printNumI(EXE, CENTER, 47);
  Serial.println(f2_D);

  */
  
    
  
    
  if(Serial.available())
  {
    
    give_me = Serial.read();

    switch(give_me)
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
