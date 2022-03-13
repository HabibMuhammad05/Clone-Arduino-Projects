/*----------------Servo_Multiple_Access-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/

#include <Servo.h>
Servo myservo3;
Servo myservo2;
Servo myservo; 
int pos3;
int pos2;
int pos;  

int spd = 10;
int dly = 200;
int sw = 200;

void setup() {
}

void loop() {
/*---------------servo1----------------*/
 myservo.attach(9);
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(spd);
  }
 delay(dly);
   for (pos = 180; pos >= 0; pos -= 1) {
     myservo.write(pos);            
     delay(spd);     
   }
 myservo.detach();
  delay(sw);
/*---------------servo2----------------*/
 myservo2.attach(10);
  for (pos2 = 0; pos2 <= 180; pos2 += 1) {
    myservo2.write(pos2);
    delay(spd);
  }
 delay(dly);
   for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
     myservo2.write(pos2);            
     delay(spd);     
   }
 myservo2.detach();
  delay(sw);
/*---------------servo3----------------*/
 myservo3.attach(11);
  for (pos3 = 0; pos3 <= 180; pos3 += 1) {
    myservo3.write(pos3);
    delay(spd);
  }
 delay(dly);
   for (pos3 = 180; pos3 >= 0; pos3 -= 1) {
     myservo3.write(pos3);            
     delay(spd);     
   }
 myservo3.detach();
  delay(sw);
}
