/*----------------LCD_I2C_RunningText-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/

/*AT-MO PRODUCTION
  I2C ARDUINO
  tolong jika menggunakan code ini
  mohon masukan sumber seperti di bawah ini
  "AT-MO PRODUCTION
  EDIT BY OGI SINATRA"
*/
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
//Ubah alamat 0x27 dengan alamat i2C kamu

void setup(){
  lcd.begin (16,2); //LCD untuk ukuran 16x2
  lcd.setCursor(1,0);
  lcd.print("S");delay(200); lcd.print("E");delay(200);
  lcd.print("L");delay(200); lcd.print("A");delay(200);
  lcd.print("M");delay(200); lcd.print("A");delay(200);
  lcd.print("T");delay(200); lcd.print(" ");delay(500);
  lcd.print("D");delay(200); lcd.print("A");delay(200);
  lcd.print("T");delay(200); lcd.print("A");delay(200);
  lcd.print("N");delay(200); lcd.print("G");delay(1000);

  lcd.setCursor(2,1);
  lcd.print("M");delay(200); lcd.print("A");delay(200);
  lcd.print("S");delay(200); lcd.print("U");delay(200);
  lcd.print("K");delay(200); lcd.print("K");delay(200);
  lcd.print("A");delay(200); lcd.print("N");delay(200);
  lcd.print(" ");delay(200); lcd.print("P");delay(200);
  lcd.print("I");delay(200); lcd.print("N");delay(3000);
  lcd.clear();
  }
  
void loop(){  
  int u;
  lcd.setCursor(14, 0);
  lcd.print("Silahkan masukkan pn anda");
  for (u = 0 ; u < 16; u++) {
    lcd.scrollDisplayLeft();
    //lcd.scrollDisplayRight();
    delay(400);
  }
}
