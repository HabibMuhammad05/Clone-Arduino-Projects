
/*----------------rfid RC522 DoorLock-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

//Coding berikut dibuat oleh Dani untuk www.belajarduino.com
//Semoga bermanfaat bagi yang sedang belajar RFID system
//Support by RAJACELL - BEKASI
//Semua module yang dibutuhkan dapat dibeli di www.tokopedia.com/rajacell 

#include <RFID.h>

#include <Wire.h>  // i2C Conection Library
#include <LiquidCrystal_I2C.h>  //Memanggil i2C LCD Library
#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <SPI.h>
#include <LCD.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);
int serNum[5];          //Variable buffer Scan Card
int cards[][5] = {      //ID Kartu yang diperbolehkan masuk
  {73,3,217,227}
  
};

bool access = false;

LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
Password password = Password("1478"); //<-- TULIS PASSWORD SISTEM ANDA DISINI

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 7, 6, 5, 4 };
byte colPins[COLS] = { 3, 2, 1, 0 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


const int buzzer = 9;   //Passive buzzer ke Pin D7 dan GND
const int doorLock = 8; //Driver Selenoid Door Lock/Relay input ke pin D8

int alarm = 0;
uint8_t alarmStat = 0;
uint8_t maxError = 5;

unsigned long previousMillis = 0; 
const long interval = 1000;  
uint8_t pwMode=0;
uint8_t pwPos=0;

void setup(){
    Serial.begin(9600);
    lcd.begin(16,2);
    SPI.begin();
    rfid.init();
    keypad.addEventListener(keypadEvent); //add an event listener for this keypad
   
    pinMode(doorLock, OUTPUT);
    digitalWrite(doorLock, HIGH);

  tone (buzzer,1200);
  lcd.setCursor (0,0);
  lcd.print(F("  RFID System   "));
  lcd.setCursor (0,1);
  lcd.print(F(" Control Access "));
  delay (2000);
  lcd.clear();
  noTone (buzzer);
}

void loop(){
  keypad.getKey();  //Reading Keypad
  
  if (alarm >= maxError){
    alarmStat = 1;    }
  
  if (alarmStat == 0 && pwMode == 0){
  lcd.setCursor (0,0);
  lcd.print(F(" -System Ready- "));
  unsigned long currentMillis = millis();

//Membuat perubahan tulisan pada LCD tanpa menggunakan delay
//Pada sistem stanby sama sekali tidak boleh ada delay untuk menghindari Keypad NGADAT

/*if (currentMillis - previousMillis >= interval) {
      //previousMillis = currentMillis;
  lcd.setCursor (0,1);
  lcd.print(F(" Scan Your Card "));
  } */
  if (currentMillis - previousMillis >= interval) {      
      //previousMillis = currentMillis;
  lcd.setCursor (0,1);
  lcd.print(F(" Scan Your Card "));
  }

  if (currentMillis - previousMillis >= (2*interval)) {
      previousMillis = currentMillis;
  lcd.setCursor (0,1);
  lcd.print(F(" Enter Password "));
  }
  
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
            
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = true;
                      break;
                  } else {
                      access = false;
                  }
              }
              if(access) break;
            }   
        }
        
       if(access){
          Serial.println("Welcome!");
          lcd.setCursor (0,0);
          lcd.print(F(" Akses diterima "));
          lcd.setCursor (0,1);
          lcd.print("ID:");
          lcd.print(rfid.serNum[0]); lcd.print(rfid.serNum[1]);
          lcd.print(rfid.serNum[2]); lcd.print(rfid.serNum[3]);
          lcd.print(rfid.serNum[4]);
          ACCEPT ();
           } 
      
      else {
           alarm = alarm+1;
           Serial.println("Not allowed!"); 
           lcd.setCursor (0,0);
           lcd.print(F(" Akses ditolak  "));
           lcd.setCursor (0,1);
           lcd.print("ID:");
           lcd.print(rfid.serNum[0]); lcd.print(rfid.serNum[1]);
           lcd.print(rfid.serNum[2]); lcd.print(rfid.serNum[3]);
           lcd.print(rfid.serNum[4]);
           RIJECT ();    
       }        
    }
//Coding berikut dibuat oleh Dani untuk www.belajarduino.com
//Semoga bermanfaat bagi yang sedang belajar RFID system
//Support by RAJACELL - BEKASI
//Semua module yang dibutuhkan dapat dibeli di www.tokopedia.com/rajacell 
    rfid.halt();
}
if (alarmStat == 1) {
  lcd.setCursor (0,0);
  lcd.print(F("-System LOCKED- "));
  lcd.setCursor (0,1);
  lcd.print(F(" Please Wait "));
for(int i=60; i>0; i--){
tone (buzzer,9000);
delay(300);
tone (buzzer,10000);
delay(300);
lcd.setCursor (13,1); lcd.print(i);
lcd.print(F("  "));delay (1000);}
noTone (buzzer);
alarmStat = 0;
alarm = 0;
  }
}
//Coding berikut dibuat oleh Dani untuk www.belajarduino.com
//Semoga bermanfaat bagi yang sedang belajar RFID system
//Support by RAJACELL - BEKASI
//Semua module yang dibutuhkan dapat dibeli di www.tokopedia.com/rajacell 
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
  case PRESSED:
  Serial.print("Pressed: ");
  Serial.println(eKey);
  
  pwMode =1;
  pwPos=pwPos+1;
  if(pwPos==1){lcd.clear();}
  lcd.setCursor (0,0);
  lcd.print(F("Password Entered"));
  if(pwPos<5){lcd.setCursor (5+pwPos,1);
  lcd.print(F("*"));}
  
  switch (eKey){
    case '*': checkPassword(); break;
    //case '#': password.reset(); break;
    
    default: password.append(eKey);
     }
  }
}
//Coding berikut dibuat oleh Dani untuk www.belajarduino.com
//Semoga bermanfaat bagi yang sedang belajar RFID system
//Support by RAJACELL - BEKASI
//Semua module yang dibutuhkan dapat dibeli di www.tokopedia.com/rajacell 
void checkPassword(){
  if (password.evaluate()){

    Serial.println("Password OK");
    lcd.setCursor (0,1);
    lcd.print(F("   -Accepted-   "));
    ACCEPT ();
    password.reset();
    pwPos=0;
    //Add code to run if it works
    
  }else{
    Serial.println("Password SALAH");
    lcd.setCursor (0,1);
    lcd.print(F("   -Rejected-   "));
    alarm = alarm+1;
    RIJECT ();
    password.reset();
    pwPos=0;
    //add code to run if it did not work
  } 
}
//Coding berikut dibuat oleh Dani untuk www.belajarduino.com
//Semoga bermanfaat bagi yang sedang belajar RFID system
//Support by RAJACELL - BEKASI
//Semua module yang dibutuhkan dapat dibeli di www.tokopedia.com/rajacell 
void ACCEPT () {
           digitalWrite(doorLock, LOW);
           tone (buzzer,7777);
           delay(200);
           tone (buzzer,9999);
           delay(200);
           tone (buzzer,8888 );
           delay(300);
           noTone(buzzer);  
           delay(600);
           lcd.setCursor (0,0);
           lcd.print(F(" Silahkan Masuk "));
           lcd.setCursor (0,1);
           lcd.print(F("AutoLock setelah"));
           for(int i=5; i>0; i--){
            lcd.setCursor (15,1); lcd.print(i);
            delay (1000);
           }
           digitalWrite(doorLock, HIGH);
           pwMode =0;
           lcd.clear();}
//Coding berikut dibuat oleh Dani untuk www.belajarduino.com
//Semoga bermanfaat bagi yang sedang belajar RFID system
//Support by RAJACELL - BEKASI
//Semua module yang dibutuhkan dapat dibeli di www.tokopedia.com/rajacell 
void RIJECT () {
           tone (buzzer,900);
           delay(200);
           noTone(buzzer);
           delay(200);
           tone (buzzer,900);
           delay(200);
           noTone (buzzer);  
           delay(500);
           pwMode =0;
           lcd.clear();  
}

/*--------------------------------------V1.0-----------------------------------------*
#include <Keypad.h>
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
int Relay = 10;
int merah = 11;
int hijau = 12;

char* password = "22";  // change the password here, just pick any 3 numbers
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 7, 6, 5, 4 };
byte colPins[COLS] = { 3, 2, 1, 0 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
lcd.begin (16,2);
LockedPosition(true);
pinMode(merah, OUTPUT);
pinMode(hijau, OUTPUT);
pinMode(Relay, OUTPUT);

 
}

void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '*')
{
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 2)
{
LockedPosition(false);
}
delay(0);
}
void LockedPosition(int locked)
{
if (locked) //terkunci
{
lcd.clear();
lcd.setCursor(1,0);
  lcd.print("S");delay(200); lcd.print("E");delay(200);
  lcd.print("L");delay(200); lcd.print("A");delay(200);
  lcd.print("M");delay(200); lcd.print("A");delay(200);
  lcd.print("T");delay(200); lcd.print(" ");delay(500);
  lcd.print("D");delay(200); lcd.print("A");delay(200);
  lcd.print("T");delay(200); lcd.print("A");delay(200);
  lcd.print("N");delay(200); lcd.print("G");delay(1000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("M");delay(200); lcd.print("A");delay(200);
  lcd.print("S");delay(200); lcd.print("U");delay(200);
  lcd.print("K");delay(200); lcd.print("K");delay(200);
  lcd.print("A");delay(200); lcd.print("N");delay(200);
  lcd.print(" ");delay(200); lcd.print("P");delay(200);
  lcd.print("I");delay(200); lcd.print("N");delay(3000);
digitalWrite(merah, LOW);
digitalWrite(hijau, HIGH);
digitalWrite(Relay, HIGH);

}
else  //terbuka
{
lcd.clear();
lcd.setCursor(1, 0); 
lcd.print("Silahkan buka");



digitalWrite(merah, HIGH);
digitalWrite(hijau, LOW);
digitalWrite(Relay, LOW);
delay(1000);
digitalWrite(merah, LOW);
digitalWrite(hijau, HIGH);
digitalWrite(Relay, HIGH);
}
}*/
