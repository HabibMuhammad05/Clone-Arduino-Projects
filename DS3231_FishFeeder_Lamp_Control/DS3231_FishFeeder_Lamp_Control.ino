/*---------------------LAMP&FISH FEEDER CONTROL-------------------------*/
/*-----------------Source Code by Habib.m @Hab_mz-----------------------*/
/*--------------Modified & Adapted by Habib.m @Hab_mz-------------------*/
/*------------------------------V4.2------------------------------------*/
/*----------------------------------------------------------------------*/
/*------------------------------SERVO-----------------------------------*/
#include <Servo.h>
Servo myservo;
/*-------------------------------LCD------------------------------------*/
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
/*-----------------------------DS3231-----------------------------------*/
#include <DS3231.h>
DS3231 rtc(SDA,SCL);
String hari;
String waktu;
String tanggal;
/*---------------------------PUSHBUTTON---------------------------------*/
unsigned long waktulcd=0;
int butPak=7;
int butOn=8;
int count;

const int buzzer = 5;
const int relay2=2;

void setup() {
  rtc.begin();
  lcd.begin(16, 2);
  Serial.begin(115200);
  pinMode(relay2,OUTPUT);
  digitalWrite(relay2,HIGH);
  pinMode(buzzer, OUTPUT);
  pinMode(butPak,INPUT);
  pinMode(butOn,INPUT);
                        //rtc.setTime(22,00,00);
  myservo.attach(11);
  myservo.write(83);
  delay(500);
  myservo.detach();
  tone(buzzer, 2000); delay(2000); noTone(buzzer);
}

void loop() {
unsigned long waktusekarang = millis();
if(waktusekarang-waktulcd >= 1000){
  waktu=rtc.getTimeStr();
  Serial.println(waktu);
    lcd.setCursor(2,0);lcd.print("JAM:"); lcd.print(rtc.getTimeStr());
    lcd.setCursor(0,1);
    lcd.print("P=");lcd.print("5"); lcd.print(":");lcd.print("30   ");
    lcd.print("M=");lcd.print("20");lcd.print(":");lcd.print("00");
  Serial.println(waktusekarang);
  waktulcd=millis();
}
/*---------------------------BUTTON-------------------------------*/
if(digitalRead(butPak) == HIGH ){
    Serial.println("pakan");
    buzPakan();
    pakan();
  }
else if(digitalRead(butOn) == HIGH){
    if(count==0){
      Serial.println("lampu mati");
      buzLampu();
      digitalWrite(relay2,LOW);
      count++;
    }
    else if(count==1){
      Serial.println("lampu hidup");
      buzPakan();
      digitalWrite(relay2,HIGH);
      count--;
    }
}
/*---------------------------PAKAN-------------------------------*/

if(waktu=="06:30:01"){
    Serial.println("Morning Feed!!");
    buzPakan();
    pakan();
  }
else if(waktu=="18:30:01"){
    Serial.println("Night Feed!!");
    buzPakan();
    pakan();
  }

/*-----------------------------LAMPU----------------------------------*/
  
if(waktu=="05:30:01"){
    Serial.println("Lamp ON!!");
    buzPakan();
    digitalWrite(relay2,HIGH);
  }
else if(waktu=="11:00:01"){
    Serial.println("Lamp OFF");
    buzLampu();
    digitalWrite(relay2,LOW);
  }
else if(waktu=="14:00:01"){
    Serial.println("Lamp ON!!");
    buzPakan();
    digitalWrite(relay2,HIGH);
  }
else if(waktu=="20:00:01"){
    Serial.println("Lamp OFF");
    buzLampu();
    digitalWrite(relay2,LOW);
  }
else if(waktu=="23:00:01"){
    Serial.println("Lamp OFF");
    buzLampu();
    digitalWrite(relay2,LOW);
  }
}

/*-----------------------------VOID----------------------------------*/

void pakan(){
      myservo.attach(11);
      myservo.write(155);              
      delay(350);
      myservo.detach();
      delay(10);

      myservo.attach(11);
      myservo.write(83);              
      delay(500);
      myservo.detach();
      delay(100); 

      myservo.attach(11);
      myservo.write(155);              
      delay(350);
      myservo.detach();
      delay(10);

      myservo.attach(11);
      myservo.write(83);              
      delay(500);
      myservo.detach();
      delay(100); 
}
void buzPakan(){
      tone(buzzer, 261);
      delay(200);
      tone(buzzer, 329);
      delay(200);
      tone(buzzer, 392);
      delay(200);
      tone(buzzer, 493);
      delay(200);
      tone(buzzer, 523);
      delay(235);
      noTone(buzzer);
      delay(100);
}
void buzLampu(){
      tone(buzzer, 523);
      delay(200);
      tone(buzzer, 493);
      delay(200);
      tone(buzzer, 392);
      delay(200);
      tone(buzzer, 329);
      delay(200);
      tone(buzzer, 261);
      delay(200);
      noTone(buzzer);
      delay(100);
}


/*------------------------------@Hab_Mz--------------------------------*/
/*--------------------------------V1.0---------------------------------*/
/*
/*------------------------------SERVO-----------------------------------
#include <Servo.h>
Servo myservo;
/*------------------------------LCD-----------------------------------
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
/*-----------------------------DS3231---------------------------------
#include <DS3231.h>
DS3231 rtc(SDA,SCL);
const int buzzer = A0;
const int relay2=11;
bool on=LOW;
bool off=HIGH;
String hari;
String waktu;
String tanggal;

void setup() {
  rtc.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(relay2,OUTPUT);
  digitalWrite(relay2,off);
pinMode(buzzer, OUTPUT);
}

void loop() {
  hari=rtc.getDOWStr();
  waktu=rtc.getTimeStr();
  tanggal=rtc.getDateStr();
  Serial.println(waktu);
    lcd.setCursor(2,0);lcd.print("JAM:"); lcd.print(rtc.getTimeStr());
    lcd.setCursor(0,1);
    lcd.print("P=");   lcd.print("5"); lcd.print(":");lcd.print("30");
    lcd.print("   M=");lcd.print("20");lcd.print(":");lcd.print("00");
    delay(1000);
/*---------------------------MAKAN PAGI-------------------------------
  if(waktu=="06:30:00"){
    for(int i = 0; i<5; i++){
        tone(buzzer, 600);
        delay(200);
        tone(buzzer, 500);
        delay(200);
        noTone(buzzer);
        delay(100);
    }
  Serial.println("Morning Feed!!");
    pakan();
  }
else if(waktu=="06:30:15"){
    noTone(buzzer);
    Serial.println("Feed stop");
    
  }
/*---------------------------MAKAN MALAM------------------------------
  if(waktu=="18:30:00"){
    for(int i = 0; i<5; i++){
        tone(buzzer, 600);
        delay(200);
        tone(buzzer, 500);
        delay(200);
        noTone(buzzer);
        delay(100);
    }
    Serial.println("Night Feed!!");
    pakan();
  }
  
else if(waktu=="18:30:15"){
  noTone(buzzer);
    Serial.println("Feed stop");
    
  }
/*-----------------------------LAMPU----------------------------------*
  if(waktu=="05:30:00"){
    for(int i = 0; i<2; i++){
    tone(buzzer, 800);
    delay(200);
    tone(buzzer, 1200);
    delay(200);
    noTone(buzzer);
    delay(200);
    }
    Serial.println("Lamp ON!!");
    digitalWrite(relay2,off);
  }
  
else if(waktu=="11:00:00"){
    for(int i = 0; i<2; i++){
    tone(buzzer, 800);
    delay(200);
    tone(buzzer, 1200);
    delay(200);
    noTone(buzzer);
    delay(200);
    }
    Serial.println("Lamp OFF");
    digitalWrite(relay2,on);
  }

if(waktu=="13:30:00"){
    for(int i = 0; i<2; i++){
    tone(buzzer, 800);
    delay(200);
    tone(buzzer, 1200);
    delay(200);
    noTone(buzzer);
    delay(200);
    }
    Serial.println("Lamp ON!!");
    digitalWrite(relay2,off);
  }
  
else if(waktu=="20:00:00"){
    for(int i = 0; i<2; i++){
    tone(buzzer, 800);
    delay(200);
    tone(buzzer, 1200);
    delay(200);
    noTone(buzzer);
    delay(200);
    }
    Serial.println("Lamp OFF");
    digitalWrite(relay2,on);
  }

  if(waktu=="23:00:00"){
    for(int i = 0; i<1; i++){
    tone(buzzer, 800);
    delay(200);
    tone(buzzer, 1200);
    delay(200);
    noTone(buzzer);
    delay(200);
    }
    Serial.println("Lamp ON!!");
    digitalWrite(relay2,on);
  }
  
else if(waktu=="20:00:00"){
    for(int i = 0; i<1; i++){
    tone(buzzer, 800);
    delay(200);
    tone(buzzer, 1200);
    delay(200);
    noTone(buzzer);
    delay(200);
    }
    Serial.println("Lamp OFF");
    digitalWrite(relay2,on);
  }
}

void pakan(){
    for (int i = 1; i <= 2; i ++) {
     for (int pos = 60; pos >= 5; pos -= 1) {
            myservo.attach(9);
            myservo.write(pos);              
            delay(7);}
     myservo.detach();
     delay(50);
     for (int pos = 12; pos <= 65; pos += 1) {
            myservo.attach(9);
            myservo.write(pos);              
            delay(7);}
     myservo.detach();
     delay(50);}
}

  //rtc.setDOW(THURSDAY);
  //rtc.setTime(14,20,0);
  //rtc.setDate(23,1,2020);

  */
