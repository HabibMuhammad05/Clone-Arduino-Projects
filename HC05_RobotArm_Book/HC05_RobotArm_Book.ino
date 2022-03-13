/*----------------HC05_RobotArm_Book-------------*/
/*-------------Source Code by Bolabot----------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.3-------------------------*/
#include <Servo.h>
Servo servo1,servo2,servo3,servo4,servo5,servo6;
char c;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servo1.attach(8);
servo2.attach(9);
servo3.attach(10);
servo4.attach(11);
servo5.attach(12);

servo1.write(90);
servo2.write(50);
servo3.write(450);
servo4.write(90);
servo5.write(50);//untuk tutup
}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available()){
  char c = (char)Serial.read();
  if(c=='A'){

    Serial.print("Ambil Benda");
    servo4.write(180);
    delay(700);
    servo5.write(130);
    delay(700);
    servo2.write(140);
    delay(700);
    for(int b=110;b<=50;b++){servo2.write(b); delay(25);}
    for(int c=0;c>=60;c--){servo3.write(c); delay(25);}
    delay(700);

    servo5.write(50);
    delay(700);
    servo2.write(50);
    delay(700);
    servo3.write(200);
    delay(700);
    servo4.write(90);
    delay(700);
  
  }

  else if(c=='X'){

    Serial.print("Simpan Benda");

    for(int cc = 180; cc >= 110;cc-=1){servo1.write(cc);delay(100);};
    delay(1000);
    servo4.write(90);
    delay(1000);
    for(int kk=110;kk>=50;kk-=1){servo2.write(kk);delay(1000);}
    for(int dd=0;dd<=60;dd+=1){servo3.write(dd);delay(1000);}
    delay(1000);
    servo1.write(180);
    delay(1000);
    servo2.write(120);
    delay(1000);
    servo5.write(130);
    delay(1000);
    servo2.write(50);
    delay(1000);
    servo3.write(200);
    delay(1000);

    servo1.write(90);
    delay(1000);
    servo5.write(50);
    delay(1000);
    servo2.write(50);
    delay(1000);
  }}}
/*-------------------------@Hab_mz----------------------*/
/*--------------------------V1.2------------------------
#include <Servo.h>
Servo puter;
Servo lengan;
Servo capit;
int spd = 12;
int posPut = 4;
int posLen = 3;
int poscap = 2;  
void setup() {
  Serial.begin(9600);
     puter.attach(9);
}
void loop() {
  if(Serial.available()>0){
    char data = Serial.read();
    switch (data){
 /*---------------puter----------------
      case '1': 
    Serial.println("A,Ambil");
 
    puter.write(90);
    delay(spd);
    puter.detach();

       break;
        
      case '4':  
    Serial.println("b,simpan");
    puter.attach(9);
    puter.write(0);
    delay(spd);
    puter.detach();
       break;
 /*---------------Lengan----------------
      case '2':  
         lengan.attach(10);
         posLen+=1;
         lengan.write(posLen);
         delay(spd);
         lengan.detach();
       break;

      case '5':  
         lengan.attach(10);
         posLen-=1;
         lengan.write(posLen);
         delay(spd);
         lengan.detach();
       break;
 /*---------------Capit----------------  
      case '3':  
         capit.attach(11);
         poscap+=1;
         capit.write(poscap);
         delay(spd);
         capit.detach();
       break;

      case '6': 
         capit.attach(11);
         poscap-=1;
         capit.write(poscap);
         delay(spd);
         capit.detach();
       break;
    }
    Serial.print(data);
  }
}*/

/*-------------------------@Hab_mz----------------------*/
/*--------------------------V1.1------------------------
#include <Servo.h>
Servo servo1,servo2,servo3,servo4,servo5,servo6;
char c;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servo1.attach(8);
servo2.attach(9);
servo3.attach(10);
servo4.attach(11);
servo5.attach(12);

servo1.write(180);
servo2.write(110);
servo3.write(0);
servo4.write(180);
servo5.write(180);//untuk tutup
}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available()){
  char c = (char)Serial.read();
  if(c=='A'){

    Serial.print("Ambil Benda");
    servo4.write(180);
    delay(700);
    servo5.write(50);
    delay(700);
    for(int b=110;b<=50;b++){servo2.write(b); delay(25);}
    for(int c=0;c>=60;c--){servo3.write(c); delay(25);}
    delay(700);

    servo5.write(180);
    delay(700);
    servo2.write(110);
    delay(700);
    servo3.write(0);
    delay(700);
    servo4.write(180);
    delay(700);
  
  }  }

  else if (c=='B');{

    Serial.print("Simpan Benda");

    for(int cc = 180; cc >= 110;cc-=1){servo1.write(cc);delay(100);};
    delay(1000);
    servo4.write(80);
    delay(1000);
    for(int kk=110;kk>=50;kk-=1){servo2.write(kk);delay(1000);}
    for(int dd=0;dd<=60;dd+=1){servo3.write(dd);delay(1000);}
    delay(1000);
   
    servo5.write(50);
    delay(1000);
    servo2.write(110);
    delay(1000);
    servo3.write(0);
    delay(1000);

    servo1.write(180);
    delay(1000);
    servo4.write(180);
    delay(1000);
    servo5.write(180);
    delay(1000);
    
  }
}*/
