#define PIR1 17
#define PIR2 18
#define Audio1 19
#define Audio2 21

void setup() {
  pinMode(PIR1,INPUT);
  pinMode(PIR2,INPUT);
  pinMode(Audio1,OUTPUT);
  pinMode(Audio2,OUTPUT);
}

void loop() {
  if(digitalRead(PIR1) == HIGH){
     digitalWrite(Audio1,LOW);
     delay(250);
  }else{
     digitalWrite(Audio1,HIGH);
  }
  
  if(digitalRead(PIR2) == HIGH){
     digitalWrite(Audio2,LOW);
     delay(250);
  }else{
     digitalWrite(Audio2,HIGH);
  }
  delay(100);
}
