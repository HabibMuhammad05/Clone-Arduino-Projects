/*-----------Keypad And Servo Doorlock------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/


#include <Keypad.h>
#include <Servo.h> 
Servo servoLamers;
int LEDhijau = 12;
int LEDmerah = 11;
Password password = Password( "2912" ); 
const byte baris = 4; //Baris
const byte kolom = 4; //Kolom
char keys[baris][kolom] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte barisPin[baris]= {9,8,7,6};
byte kolomPin[kolom]= {5,4,3,2};
Keypad keypad = Keypad( makeKeymap(keys), barisPin, kolomPin, baris, kolom );
void setup(){
  servoLamers.attach(10);
  servoLamers.write(180);
  Serial.begin(9600);
  delay(200); 
  pinMode(LEDhijau, OUTPUT);  //Indikator Terbuka
  pinMode(LEDmerah, OUTPUT);  //Indikator Terkunci
  keypad.addEventListener(keypadEvent);
}
void loop(){
  keypad.getKey();
}
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
    Serial.print("Masukkan Password: ");
    Serial.println(eKey);
    delay(10);
    Serial.write(254);
      
    switch (eKey){
      case '*': Login(); delay(1); break;
      case '#': password.reset(); delay(1); break;
      default: password.append(eKey); delay(1);
    }
  }
}
void Login(){ 
  if (password.evaluate()){ 
    Serial.println("Akses Diterima!");
    servoLamers.write(0);
    delay(1);
    digitalWrite(LEDhijau, HIGH);
  }
  else{
    Serial.println("Akses Ditolak!");
    servoLamers.write(180);
    delay(1);
    digitalWrite(LEDmerah, HIGH);
   }
}
