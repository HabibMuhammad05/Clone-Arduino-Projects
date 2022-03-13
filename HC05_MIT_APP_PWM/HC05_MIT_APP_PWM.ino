/*-----Single LED Control With MIT App Inventor------*/
/*---------Source Code by Habib.m @Hab_mz------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.0-------------------------*/
int led=11;
int neg=A4;
int val;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(neg,OUTPUT);
  analogWrite(neg,0);
}

void loop() {
  if(Serial.available()>0){
    val = Serial.read();
    Serial.println(val);
    analogWrite(led,val);
  }
}
/*----------------------@Hab_mz----------------------*/
