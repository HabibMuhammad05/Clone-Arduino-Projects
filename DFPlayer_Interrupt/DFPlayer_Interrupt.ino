/*-----------------While Loop code----------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/
/*---------------SPI Wiring Connections-----------------*/
/*--------------CLK_PIN   13  // or SCK-----------------*/
/*--------------DATA_PIN  11  // or MOSI----------------*/
/*---------------CS_PIN   10  // or SS------------------*/
/*------------------------------------------------------*/
#include <TimerOne.h>
int pb = 7;
//--------DFPlayer & SoftwareSerial Lib Setup-----------//
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"
SoftwareSerial playercomms(2,3);
DFRobotDFPlayerMini mp3;
static unsigned long timer = millis();

//----------------MAX7219 Lib Setup--------------------//
#include <MD_MAX72xx.h>
#define MAX_DEVICES  4
#define DELAYTIME  100
MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, 10, MAX_DEVICES);

void setup() {
  //-----------------MAX7219 setup-----------------------//
  mx.begin();
  
  pinMode(pb, INPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
//---------DFPlayer & SoftwareSerial Setup-------------//
  Serial.begin(9600);
  playercomms.begin(9600);
  mp3.begin(playercomms);
  mp3.volume(20);  //0-30
  
//---------------Interrupt Protocol--------------------//
//  Timer1.initialize(10000); 
//  Timer1.attachInterrupt( PIR_START ); 

}

void loop() {
  for(int i=1; i<=5; i++){
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }
}

//----------Interrupt Code(Audio + PIR Sensor)---------//
void PIR_START(){
  if(digitalRead(pb)==LOW){
    digitalWrite(A0,HIGH);
  }else{
    digitalWrite(A0,LOW);
  }
}
