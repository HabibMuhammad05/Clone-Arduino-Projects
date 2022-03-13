/*----------------LCD_I2C_Clock_WithButton-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

/*
 ###  simplest ever Arduino UNO digital clock  ###

 This clock needs only a 1602 LCD 2X16 and 2 push buttons 

 No Potentiometer for contrast, no resistors for pull-up or backlight !!!!

 * The simplest clock ever made with a Arduino UNO *    

 Button Functions:
 
 - short stroke on one of the buttons put Backlight on for 30 s
 
 Time settings
 - Press on H increments the Hours
 - Press on M increments the Minutes and resets the seconds
*/


#include "LiquidCrystal.h"

// This defines the LCD wiring to the DIGITALpins
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Digital LCD Constrast setting
int cs=9;// pin 9 for contrast PWM
const int contrast = 100;// default contrast

// initial Time display is 12:59:45 PM
int h=12;
int m=03;
int s=00;
int flag=0; //PM  1;pm   0;AM

// Time Set Buttons
int button1;
int button2;

// Pins definition for Time Set Buttons
int hs=0;// pin 0 for Hours Setting
int ms=1;// pin 1 for Minutes Setting

// Backlight Time Out 
const int Time_light=150;
int bl_TO=Time_light;// Backlight Time-Out
int bl=10; // Backlight pin
const int backlight=120; // no more then 7mA !!!

// For accurate Time reading, use Arduino Real Time Clock and not just delay()
static uint32_t last_time, now = 0; // RTC


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(hs,INPUT_PULLUP);// avoid external Pullup resistors for Button 1
  pinMode(ms,INPUT_PULLUP);// and Button 2
  analogWrite(cs,contrast);// Adjust Contrast VO
  analogWrite(bl,backlight);// Turn on Backlight
  now=millis(); // read RTC initial value  
}


void loop()
{ 
  lcd.begin(16,2);// every second
// Update LCD Display
// Print TIME in Hour, Min, Sec + AM/PM
 lcd.setCursor(0,0);
 lcd.print("Time ");
 Serial.print("Time ");
 if(h<10) lcd.print("0");Serial.print("0");// always 2 digits
 lcd.print(h);
 Serial.print(h);
 lcd.print(":");
 Serial.print(":");
 if(m<10) lcd.print("0");Serial.print("0");
 lcd.print(m);
 Serial.print(m);
 lcd.print(":");
 Serial.print(":");
 if(s<10) lcd.print("0");Serial.print("0");
 lcd.print(s);
 Serial.print(s);

 if(flag==0) lcd.print(" AM");Serial.print(" AM");
 if(flag==1) lcd.print(" PM");Serial.print(" PM");
 
 lcd.setCursor(0,1);// for Line 2
 lcd.print("GOOD MORNING");
 Serial.print("GOOD MORNING");


// improved replacement of delay(1000) 
// Much better accuracy, no more dependant of loop execution time

for ( int i=0 ;i<5 ;i++)// make 5 time 200ms loop, for faster Button response
{

  while ((now-last_time)<200) //delay200ms
  { 
    now=millis();
  }
 // inner 200ms loop
 last_time=now; // prepare for next loop 

 // read Setting Buttons
 button1=digitalRead(hs);// Read Buttons
 button2=digitalRead(ms);

 //Backlight time out 
 bl_TO--;
 if(bl_TO==0)
 {
  analogWrite(bl,0);// Backlight OFF
  bl_TO++;
 }
 
 // Hit any to activate Backlight 
 if(  ((button1==0)|(button2==0)) & (bl_TO==1)  )
 {
  bl_TO=Time_light;
  analogWrite(bl,backlight);
  // wait until Button released
  while ((button1==0)|(button2==0))
  {
   button1=digitalRead(hs);// Read Buttons
   button2=digitalRead(ms);
  }
 }
 else
 // Process Button 1 or Button 2 when hit while Backlight on 
 {
  if(button1==0){
   h=h+1;
   bl_TO=Time_light;
   analogWrite(bl,backlight);
  }

 if(button2==0){
  s=0;
  m=m+1;
  bl_TO=Time_light;
  analogWrite(bl,backlight);
  }

/* ---- manage seconds, minutes, hours am/pm overflow ----*/
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==13)
 {
  h=1;
  flag=flag+1;
  if(flag==2)flag=0;
 }


 if((button1==0)|(button2==0))// Update display if time set button pressed
 {
  // Update LCD Display
  // Print TIME in Hour, Min, Sec + AM/PM
  lcd.setCursor(0,0);
  lcd.print("Time ");
  if(h<10)lcd.print("0");// always 2 digits
  lcd.print(h);
  lcd.print(":");
  if(m<10)lcd.print("0");
  lcd.print(m);
  lcd.print(":");
  if(s<10)lcd.print("0");
  lcd.print(s);

  if(flag==0) lcd.print(" AM");
  if(flag==1) lcd.print(" PM");
 
  lcd.setCursor(0,1);// for Line 2
  lcd.print("lcd clock");
 }


 } // end if else
}// end for



// outer 1000ms loop

 s=s+1; //increment sec. counting
    
    
// ---- manage seconds, minutes, hours am/pm overflow ----
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==13)
 {
  h=1;
  flag=flag+1;
  if(flag==2)flag=0;
 } 
 

 
// Loop end
}
