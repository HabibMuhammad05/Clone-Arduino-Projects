int buzzer=3;
int sensor=2;
int pompa=13;
int val;
void setup() {
  // put your setup code here, to run once:
pinMode(sensor,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(pompa,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(sensor);
  if(val==HIGH)
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(pompa,LOW);
  }
  else
  {
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(pompa,HIGH);
    delay(5000);    
    
  }
}






