
/*---------rfid RC522 MasterCard DoorLock---------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

#include <SPI.h>
#include <MFRC522.h>
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5 //define green LED pin
#define LED_R 4 //define red LED
#define BUZZER 2 //buzzer pin
int Relay = 6;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  lcd.begin (16,2);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
  noTone(BUZZER);
  Serial.println("Tempelkan RFID...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("Kode UID ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ":");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ":"));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  Serial.println();
  Serial.print("Pesan : ");
  content.toUpperCase();
  
  if (content.substring(1) == "79:44:D8:B3") //change here the UID of the card/cards that you want to give access
  {
    lcd.clear();
    lcd.setCursor(3, 0); 
    lcd.print("SCANNING");lcd.print(".");delay(250);lcd.print(".");delay(250);lcd.print(".");delay(350);
    lcd.clear();
    lcd.setCursor(3, 0); 
    lcd.print("SCANNING");delay(250);lcd.print(".");delay(250);lcd.print(".");delay(250);lcd.print(".");delay(550);
    Serial.println("Akses diterima!");
    Serial.println();
    lcd.clear();
    lcd.setCursor(1, 0); 
    lcd.print("UID:");lcd.print(content.substring(1));
    lcd.setCursor(1, 1); 
    lcd.print("Akses diterima!");
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_R, HIGH);
    digitalWrite(Relay, LOW);
    delay(1000);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    
  }
 
 else   {
    lcd.clear();
    lcd.setCursor(2, 0); 
    lcd.print("SCANNING");lcd.print(".");delay(250);lcd.print(".");delay(250);lcd.print(".");delay(350);
    lcd.clear();
    lcd.setCursor(2, 0); 
    lcd.print("SCANNING");delay(250);lcd.print(".");delay(250);lcd.print(".");delay(250);lcd.print(".");delay(550);
    Serial.println(" Akses ditolak!");
    lcd.clear();
    lcd.setCursor(1, 0); 
    lcd.print("UID:");lcd.print(content.substring(1));
    lcd.setCursor(1, 1); 
    lcd.print("Akses ditolak!");
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(Relay, HIGH);
    tone(BUZZER, 800);
    delay(80);
    noTone(BUZZER);
    delay(50);
    tone(BUZZER, 800);
    delay(80);
    noTone(BUZZER);
    delay(50);
    tone(BUZZER, 800);
    delay(80);
    noTone(BUZZER);
    delay(1000);
  }

    lcd.clear();
    lcd.setCursor(1, 0); 
    lcd.print("Selamat datang");
    lcd.setCursor(1, 1); 
    lcd.print("Scan kartu anda");
}
