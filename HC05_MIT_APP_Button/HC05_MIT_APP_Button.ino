/*----------HC05_MIT_APP_INVENTOR_Button----------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/

int led=13;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
 
}

void loop() {
  if(Serial.available()>0){
    char data = Serial.read();
    Serial.println(data);
    switch(data){
      case '0':
        Serial.println("ledOff");
        digitalWrite(led,0);//mati
        break;
      case '1':
        Serial.println("ledOn");
        digitalWrite(led,1);//hidup
        break;
        default:
        break;
      }
    
  }
}
