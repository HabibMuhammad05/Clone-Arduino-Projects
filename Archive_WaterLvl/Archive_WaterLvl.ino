/*----------------WaterLevel_Sensor-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

const int waterSens = A1;
const int buzzer = A0;
int waterVal;

void setup() {
pinMode(buzzer, OUTPUT);
pinMode(waterSens, INPUT);
Serial.begin(9600);
}
void loop() {
  waterVal = analogRead(waterSens);
  
  Serial.println(waterVal);
  
if (waterVal >= 350){
  tone(buzzer, 1000);
  delay(200);
  tone(buzzer, 950);
  delay(200);
  tone(buzzer, 800);
  delay(300);
  noTone(buzzer);
  delay (100);
}
else{
  noTone(buzzer);
}
}

/*-----------------------V1.0---------------------------*
 * int adc_id = A0;
int HistoryValue = 0;
char printBuffer[128];
int ledPin = 13;
const int buzzerPin = 8;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    int value = analogRead(adc_id); // get adc value

    if(((HistoryValue>=value) && ((HistoryValue - value) > 10)) || ((HistoryValue<value) && ((value - HistoryValue) > 10)))
    {
      sprintf(printBuffer,"ADC%d level is %d\n",adc_id, value);
      Serial.print(printBuffer);
      if (value > 280)
      {
        tone(buzzerPin, 50,1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
        tone(buzzerPin, 50,1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(100);
    Serial.println("----------- ALARM ACTIVATED -----------"); 
      }
      else{
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
        }
      HistoryValue = value;
    }
}*/
 */
 
