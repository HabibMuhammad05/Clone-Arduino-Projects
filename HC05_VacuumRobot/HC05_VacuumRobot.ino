/*--------Bluetooth Controlled Vacuum Robot ---------*/
/*---------Source Code by Habib.m @Hab_mz------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.1-------------------------*/
const int vaccum=3;
const int mop=4;
const int bankiri=5;
const int bankanan=6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vaccum,OUTPUT);
  pinMode(mop,OUTPUT);
  pinMode(bankiri,OUTPUT);
  pinMode(bankanan,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char data = Serial.read();
    switch(data){
      //vacuum cleaner
      case '0':
        Serial.println("vacOff");
        digitalWrite(vaccum,HIGH);//mati
        break;
      case '1':
        Serial.println("vacOn");
        digitalWrite(vaccum,LOW);//hidup
        break;
      //mop
      case '2':
        Serial.println("MopOff");
        digitalWrite(mop,HIGH);//mati
        break;
      case '3':
        Serial.println("mopOn");
        digitalWrite(mop,LOW);//hidup
        break;  
      //MAJU
      case '4':
        Serial.println("maju");
        digitalWrite(bankiri,LOW);//hidup
        digitalWrite(bankanan,LOW);//hidup
        break;
      //stop
      case '5':
        Serial.println("stop");
        digitalWrite(bankiri,HIGH);//mati
        digitalWrite(bankanan,HIGH);//mati
        break;
      //Belok kanan
      case '6':
        Serial.println("kanan");
        digitalWrite(bankanan,HIGH);//mati
        digitalWrite(bankiri,LOW);//hidup
        break;
     //Belok kiri
      case '7':
        Serial.println("kiri");
        digitalWrite(bankanan,LOW);//hidup
        digitalWrite(bankiri,HIGH);//mati
        break;
     //EMERGENCY STOP
      case '8':
        Serial.println("emergency");
        digitalWrite(bankanan,HIGH);//mati
        digitalWrite(bankiri,HIGH);//mati
        digitalWrite(vaccum,HIGH);//mati
        digitalWrite(mop,HIGH);//mati
        break;
        default:
        break;
      }
    Serial.println(data);
  }
}
/*-----------------------@Hab_mz-------------------*/
