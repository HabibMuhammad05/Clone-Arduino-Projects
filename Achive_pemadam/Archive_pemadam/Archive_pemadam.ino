int buzzer=3;
int sensor=2;
int val;
void setup() {
pinMode(sensor,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  val=digitalRead(sensor);
  if(val==LOW)
  {
  tone(buzzer,500);
  }
  else
  {
  noTone(buzzer);
  }
}

