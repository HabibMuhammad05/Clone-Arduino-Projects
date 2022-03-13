/*----------------DS3231_TimeSetting-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/

/*------------------------------LCD-----------------------------------*/
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
/*-----------------------------DS3231---------------------------------*/
#include <DS3231.h>
DS3231 rtc(SDA,SCL);

void setup(){
  Serial.begin(115200);
  rtc.begin();
  lcd.begin(16, 2);
  // rtc.setDate(9, 1, 2021);   //mensetting tanggal 07 april 2018
  //rtc.setTime(19,32,00);     //menset jam 22:00:00
  // rtc.setDOW(6);   
}

void loop() {
   lcd.print("JAM:");
   lcd.setCursor(6,0);
   lcd.print(rtc.getTimeStr());
   lcd.setCursor(0,1);
   lcd.print("tgl=");
   lcd.print(rtc.getDateStr());
}
