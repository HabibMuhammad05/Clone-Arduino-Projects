/*----------------DS3231_LCD_Clock-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/

#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DS3231.h>
DS3231  rtc(SDA, SCL); //prosedur pembacaan I2C
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  Serial.begin(115200);
  rtc.begin();
  lcd.begin(16, 2); 
//  pinMode(13, OUTPUT);
//  digitalWrite(13, HIGH);
 
//   rtc.setDate(6, 7, 2020); 
 //  rtc.setTime(14, 34, 00);    
//   rtc.setDOW(1);  
      
//  lcd.setCursor(1,0);
//  lcd.print("S");delay(300); lcd.print("E");delay(300);
//  lcd.print("L");delay(300); lcd.print("A");delay(300);
//  lcd.print("M");delay(300); lcd.print("A");delay(300);
//  lcd.print("T");delay(300); lcd.print(" ");delay(500);
//  lcd.print("D");delay(300); lcd.print("A");delay(300);
//  lcd.print("T");delay(300); lcd.print("A");delay(300);
//  lcd.print("N");delay(300); lcd.print("G");delay(800);
//  lcd.setCursor(0,1);
//  lcd.print("J");delay(300); lcd.print("A");delay(300);
//  lcd.print("M");delay(300); lcd.print(" ");delay(500);
//  lcd.print("D");delay(300); lcd.print("I");delay(300);
//  lcd.print("G");delay(300); lcd.print("I");delay(300);
//  lcd.print("T");delay(300); lcd.print("A");delay(300);
//  lcd.print("L");delay(300); lcd.print("  ");delay(500);
//  lcd.print("R");delay(300); lcd.print("T");delay(300);
//  lcd.print("C");delay(1500);
//  lcd.clear();
}

void loop() {
lcd.setCursor(1,0);
lcd.print(rtc.getDOWStr(1)); //prosedur pemanggilan hari
lcd.setCursor(4,0);
lcd.print(",");
 
lcd.setCursor(5,0);
lcd.print(rtc.getDateStr()); //prosedur pemanggilan tanggal
 
lcd.setCursor(4,1);
lcd.print(rtc.getTimeStr());//prosedur pemanggilan waktu

}
