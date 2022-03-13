/*-----------buzzer_Tone_Control-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

const int buzzer = 5;
void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
 for(int i = 0; i<1; i++){
      tone(buzzer, 261);
      delay(200);
//      tone(buzzer, 293);
      tone(buzzer, 329);
      delay(200);
//      tone(buzzer, 349);
//      delay(200);
      tone(buzzer, 392);
      delay(200);
//      tone(buzzer, 440);
//      delay(200);
      tone(buzzer, 493);
      delay(200);
      tone(buzzer, 523);
      delay(200);
      noTone(buzzer);
      delay(200);}

      delay(1000);
}
