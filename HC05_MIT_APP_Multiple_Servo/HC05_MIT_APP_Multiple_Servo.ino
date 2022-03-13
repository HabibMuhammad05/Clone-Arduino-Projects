/*-----Multiple Servo Control With MIT App Inventor------*/
/*---Source Code by Dejan, www.HowToMechatronics.com ----*/
/*---------Modified & Adapted by Habib.m @Hab_mz---------*/
/*-------------------------V1.1--------------------------*/

#include <Servo.h>
Servo ser1;
Servo ser2;
Servo ser3;
int ser1PPos = 90;
int ser2PPos = 150;
int ser3PPos = 35;
int val;
int MaxDeg = 180;
int spd = 5;
void setup() {
  Serial.begin(9600);
  ser1.attach(9);
  ser2.attach(10);
  ser3.attach(6);
  ser1.write(ser1PPos);
  ser2.write(ser2PPos);
  ser3.write(ser3PPos);
}

void loop() {
  if(Serial.available()>0){
    val = Serial.read();
    Serial.println(" ");
    Serial.println(val);
/*-----------------------Servo1---------------------------*/
   if (val >= 0 && val <83){
       int ser1pos = val;
       ser1pos = map(ser1pos, 0, 82, 0, MaxDeg);
       Serial.println("Servo1");
       Serial.println(ser1pos);
       if(ser1PPos > ser1pos) {
          for( int j = ser1PPos; j >= ser1pos; j--){
               ser1.write(j);
               delay(spd);}}
       if(ser1PPos < ser1pos) {
          for( int j = ser1PPos; j <= ser1pos; j++){
              ser1.write(j);
              delay(spd);}}
       ser1PPos = ser1pos;
   }
/*-----------------------Servo2---------------------------*/
   if (val >= 82 && val <167){
       int ser2pos = val;
       ser2pos = map(ser2pos, 83, 166, 0, MaxDeg);
       Serial.println("Servo2");
       Serial.println(ser2pos);
       if (ser2PPos > ser2pos) {
          for ( int j = ser2PPos; j >= ser2pos; j--){
               ser2.write(j);
               delay(spd);}
       }
       if (ser2PPos < ser2pos) {
          for ( int j = ser2PPos; j <= ser2pos; j++){
              ser2.write(j);
              delay(spd);}
      }
      ser2PPos = ser2pos;
   }
/*-----------------------Servo3---------------------------*/
   if (val >= 166 && val <249){
       int ser3pos = val;
       ser3pos = map(ser3pos, 83, 166, 0, MaxDeg);
       Serial.println("Servo3");
       Serial.println(ser3pos);
       if (ser3PPos > ser3pos) {
          for ( int j = ser3PPos; j >= ser3pos; j--){
               ser3.write(j);
               delay(spd);}
       }
       if (ser3PPos < ser3pos) {
          for ( int j = ser3PPos; j <= ser3pos; j++){
              ser3.write(j);
              delay(spd);}
      }
      ser3PPos = ser3pos;
   }}}
   
/*------------------@Hab_mz--------------------*/
/*-------------------V1.0----------------------
#include <Servo.h>

Servo ser;
Servo ser2;
Servo ser3;

void setup() {
  Serial.begin(9600);
  ser.attach(9);
  ser2.attach(10);
  ser3.attach(6);
}

void loop() {
  if(Serial.available()>0){
    val = Serial.read();
    Serial.println(" ");
    Serial.println(val);

   if (val >= 0 && val <83){
       int led1pos = val;
       led1pos = map(led1pos, 0, 82, 0, 180);
       Serial.println("led1");
       Serial.println(led1pos);
       ser.write(led1pos);delay(15);}
       
   if (val >= 82 && val <167){
       int led2pos = val;
       led2pos = map(led2pos, 83, 166, 0, 180);
       Serial.println("led2");
       Serial.println(led2pos);
       ser2.write(led2pos);delay(15);}
       
   if (val >= 166 && val <249){
       int led3pos = val;
       led3pos = map(led3pos, 167, 248, 0, 180);
       Serial.println("led3");
       Serial.println(led3pos);
       ser3.write(led3pos);delay(15);}
  }}*/
/*------------------@Hab_mz--------------------*/  
