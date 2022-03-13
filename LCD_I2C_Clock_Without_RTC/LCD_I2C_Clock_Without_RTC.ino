/*------------LCD Clock without RTC--------------*/
/*----------Source Code by ----------------------*/
/*----Modified & Adapted by Habib.m @Hab_mz------*/
/*--------------------V1.1-----------------------*/

// include the library
#include <LiquidCrystal.h>


// initialize the interface pins
LiquidCrystal lcd(2,3,4,5,6,7);
int s,m,h,a,d,state,state1,state2,dg,cnt;

// the 8 arrays that form each segment of the custom numbers
byte bar1[8] = 
{
        B11100,
        B11110,
        B11110,
        B11110,
        B11110,
        B11110,
        B11110,
        B11100
};
byte bar2[8] =
{
        B00111,
        B01111,
        B01111,
        B01111,
        B01111,
        B01111,
        B01111,
        B00111
};
byte bar3[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar4[8] =
{
        B11110,
        B11100,
        B00000,
        B00000,
        B00000,
        B00000,
        B11000,
        B11100
};
byte bar5[8] =
{
        B01111,
        B00111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00011,
        B00111
};
byte bar6[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar7[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00111,
        B01111
};
byte bar8[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};



void setup()
{
  // assignes each segment a write number
  lcd.createChar(1,bar1);
  lcd.createChar(2,bar2);
  lcd.createChar(3,bar3);
  lcd.createChar(4,bar4);
  lcd.createChar(5,bar5);
  lcd.createChar(6,bar6);
  lcd.createChar(7,bar7);
  lcd.createChar(8,bar8);
  state=1;
  state1=1;
  state2=1;
  // sets the LCD's rows and colums:
  lcd.begin(16, 2);
  pinMode(8,INPUT);
    pinMode(9,INPUT);
      pinMode(10,INPUT);
  s=0;
  m=0;
   h=0;
a=0;
}

void custom0(int col)
{ // uses segments to build the number 0
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(8); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom1(int col)
{
  lcd.setCursor(col,0);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col,1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom2(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void custom3(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1); 
}

void custom4(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom5(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom6(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom7(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom8(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom9(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(7);  
  lcd.write(6);  
  lcd.write(1);
}

void printNumber(int value, int col) {
  if (value == 0) {
    custom0(col);
  } if (value == 1) {
    custom1(col);
  } if (value == 2) {
    custom2(col);
  } if (value == 3) {
    custom3(col);
  } if (value == 4) {
    custom4(col);
  } if (value == 5) {
    custom5(col);
  } if (value == 6) {
    custom6(col);
  } if (value == 7) {
    custom7(col);
  } if (value == 8) {
    custom8(col);
  } if (value == 9) {
    custom9(col);
  }      
}  


  
 
 
  
 




void loop()

{
  if(digitalRead(8)&&state==1){
    cnt++;
    state=0;
    if(cnt>3){
      cnt=0;
      }
    }else if(!digitalRead(8)&&state==0){
    state=1;
    }

if(digitalRead(9)&&state1==1){
    dg=1;
    state1=0;
     
    }else if(!digitalRead(9)&&state1==0){
    state1=1;
    }

if(digitalRead(10)&&state2==1){
     dg=-1;
     state2=0;
    }else if(!digitalRead(10)&state2==0){
    state2=1;
    }
    switch(cnt){
      case 1:
      m=m+dg;
      dg=0;  if(m>59){
    m=59;}
    if(m<0){
    m=0;}
      break;
     
      case 2:
      h=h+dg;
      dg=0;if(h>11){
    h=11;}
    if(h<0){
    h=0;}
      break;
          case 3:
     if(dg==1){
    a=1;
    dg=0;}
     if(dg==-1){
    a=0;
    dg=0;}
      break;
      }
  if(s>59){
    s=0;
    m++;
  
  if(m>59){
    m=0;
   h++;
  
  if(h>11){
    h=0;
    a=!a;
  } 
  }
  }
  d=h%10;
  printNumber(d, 3);
  d=h/10;
   printNumber(d, 0);

       d=m%10;
     printNumber(d, 10);
     d=m/10;
     printNumber(d, 7);
     lcd.setCursor(14, 0);
     if(a){
       lcd.print("AM");
      }else{
         lcd.print("PM");
        }
        if(cnt==0){
           s++;
          lcd.setCursor(6, 0);
      lcd.print(" ");
       lcd.setCursor(6, 1);
      lcd.print(" ");
      delay(500);
    lcd.setCursor(6, 0);
      lcd.print(".");
       lcd.setCursor(6, 1);
      lcd.print(".");
      delay(500);
       }
}  



/*-------------------------------------V1.0-----------------------------------------*/
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
#include <TimeLib.h>

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

void setup() {
  // set up the LCD's number of columns and rows:
lcd.begin(16, 2);
  Serial.begin(9600);
  while (!Serial) ; // Needed for Leonardo only
  setSyncProvider( requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
  lcd.print("Loading.....");
  //lcd.print("hello, world!");
}

void loop() {
  if (Serial.available()) {
    processSyncMessage();
  }
  if (timeStatus()!= timeNotSet) {
    digitalClockDisplay();  
  }
  if (timeStatus() == timeSet) {
    digitalWrite(13, HIGH); // LED on if synced
  } else {
    digitalWrite(13, LOW);  // LED off if needs refresh
  }
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
}

void digitalClockDisplay(){
  // digital clock display of the time
  lcd.print("Time ");
  lcd.print(hour());
  Serial.print(hour());Serial.print(":");
  printDigits(minute());Serial.print(minute());Serial.print(":");
  printDigits(second());Serial.print(second());
  lcd.setCursor(0, 1);
  lcd.print("Date ");
  lcd.print(day());
  lcd.print("/");
  lcd.print(month());
  lcd.print("/");
  lcd.print(year()); 
   
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  lcd.print(":");
  if(digits < 10)
    lcd.print('0');
  lcd.print(digits);
}


void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     if( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
       setTime(pctime); // Sync Arduino clock to the time received on the serial port
     }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);  
  return 0; // the time will be sent later in response to serial mesg
}
