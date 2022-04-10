/*---------------PushButton Control------------------*/
/*---------Source Code by Habib.m @Hab_mz------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.0-------------------------*/
int butPak=7;
int butOn=8;
int count;
#include <Servo.h>
Servo myservo;
const int buzzer = 5;
const int relay2=2;
void setup() {
  Serial.begin(115200);
  pinMode(butPak,INPUT);
  pinMode(butOn,INPUT);
  
  pinMode(relay2,OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(relay2,HIGH);

}

void loop() {
  if(digitalRead(butPak) == HIGH ){
    Serial.println("pakan");
    buzPakan();
    pakan();
  }
else if(digitalRead(butOn) == HIGH){
    if(count==1){
      Serial.println("lampu hidup");
      buzLampu();
      count--;
    }
    else if(count==0){
      Serial.println("lampu mati");
      buzLampu();
      count++;
    }
}
}

void pakan(){
      myservo.attach(3);
      myservo.write(155);              
      delay(350);
      myservo.detach();
      delay(10);

      myservo.attach(3);
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
/*---------------------@Hab_Mz-----------------------*/
