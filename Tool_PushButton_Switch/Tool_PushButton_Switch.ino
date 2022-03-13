/*---------------PushButton Led Control----------------*/
/*---------Source Code by Habib.m @Hab_mz-------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.0-------------------------*/
int butPak=7;
int butOn=8;
int butOff=9;
const int buzzer = 5;
int count;
void setup() {
  Serial.begin(115200);
  pinMode(butPak,INPUT);
  pinMode(butOn,INPUT);
  pinMode(butOff,INPUT);
}

void loop() {
  
if(digitalRead(butOn) == HIGH){
    if(count==1){
      Serial.println("lampu hidup");
      buzLampu();
      count--;
    }
    else if(count==0){
      Serial.println("lampu mati");
      buzLampu();
      count++;
    }
}
}

void buzLampu(){
      tone(buzzer, 523);
      delay(200);
      tone(buzzer, 493);
      delay(200);
      tone(buzzer, 392);
      delay(200);
      tone(buzzer, 329);
      delay(200);
      tone(buzzer, 261);
      delay(200);
      noTone(buzzer);
      delay(100);
}
/*---------------------@Hab_Mz-----------------------*/
