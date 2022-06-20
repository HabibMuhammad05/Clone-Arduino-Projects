/*-------------L293D Coffin Car Bluetooh & LineFollower-----------------*/
/*-----------------Source Code by Habib.m @Hab_mz-----------------------*/
/*--------------Modified & Adapted by Habib.m @Hab_mz-------------------*/
/*------------------------------V1.2------------------------------------*/
/*----------------------------------------------------------------------*/

#include <SoftwareSerial.h>
SoftwareSerial bt (6,7);
int pwm1 = 11;
int in1 = 13;
int in2 = 12;
int in3 = 8;
int in4 = 10;
int pwm2 = 9;

int Skanan = 5;
int Stengah = 3;
int SKiri = 4;

String perintah;

void setup(){
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(pwm1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(pwm2,OUTPUT);
  
  pinMode(Skanan, INPUT_PULLUP);
  pinMode(Stengah, INPUT_PULLUP);
  pinMode(SKiri, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(2)==0){
    lineCar();
  }else{
    btCar();
  }
}

void btCar(){
    if(bt.available()!=0){
        perintah = bt.readString();
        Serial.print(perintah);
        Serial.println();
    
       if (perintah == "MAJU")  { maju(200); }
       if (perintah == "MUNDUR"){ mundur(200);  delay(400); berhenti();}
       if (perintah == "KANAN") { kanan(200,0); delay(250); berhenti();}
       if (perintah == "Skan")  { serongkanan(255,100); delay(1000); berhenti();}
       if (perintah == "KIRI")  { kiri(0,200);  delay(250); berhenti();}
       if (perintah == "Skir")  { serongkiri(100,255); delay(1000); berhenti();}
       if (perintah == "STOP")  { berhenti();}
       delay(10);
    }
}

void lineCar(){
    if ((digitalRead(SKiri)== 0 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 0 ))  {Serial.println("Maju"); maju2(100);}
 
    if ((digitalRead(SKiri)== 1 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 0 ))  {Serial.println("Kiri"); kiri2(120,100);}
    if ((digitalRead(SKiri)== 1 )&&(digitalRead(Stengah)== 0 )&&(digitalRead(Skanan)== 0 ))  {Serial.println("Kiri"); kiri2(120,100);}
 
    if ((digitalRead(SKiri)== 0 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 1 ))  {Serial.println("Kanan");kanan2(100,120);}
    if ((digitalRead(SKiri)== 0 )&&(digitalRead(Stengah)== 0 )&&(digitalRead(Skanan)== 1 ))  {Serial.println("Kanan");kanan2(100,120);}
 
    if ((digitalRead(SKiri)== 1 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 1 ))  {Serial.println("Stop"); berhenti();}
}

void maju(int spdmaju){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdmaju);
  analogWrite(pwm2, spdmaju);
}

void mundur(int spdmundur){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
  
  analogWrite(pwm1, spdmundur);
  analogWrite(pwm2, spdmundur);
}

void kanan(int spdkiri, int spdkanan){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdkiri);
  analogWrite(pwm2, spdkanan);
}

void serongkanan(int spdkiri, int spdkanan){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdkiri);
  analogWrite(pwm2, spdkanan);
}

void kiri(int spdkiri2, int spdkanan2){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdkiri2);
  analogWrite(pwm2, spdkanan2);
}

void serongkiri(int spdkiri2, int spdkanan2){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdkiri2);
  analogWrite(pwm2, spdkanan2);
}

void berhenti(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);

  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}

void maju2(int spdmaju){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdmaju);
  analogWrite(pwm2, spdmaju);
}

void kiri2(int spdkiri, int spdkanan){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdkiri);
  analogWrite(pwm2, spdkanan);
}

void kanan2(int spdkiri2, int spdkanan2){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
  
  analogWrite(pwm1, spdkiri2);
  analogWrite(pwm2, spdkanan2);
}
