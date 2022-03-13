/*----Multiple LED Control With MIT App Inventor-----*/
/*---------Source Code by Habib.m @Hab_mz------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.1-------------------------*/
int val;
int led1=11;
int led2=9;
int led3=6;
int neg=8;
int neg2=7;
int neg3=12;
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(neg,OUTPUT);
  pinMode(neg2,OUTPUT);
  pinMode(neg3,OUTPUT);
  digitalWrite(neg,0);
  digitalWrite(neg2,0);
  digitalWrite(neg3,0);
}

void loop() {
  if(Serial.available()>0){
    val = Serial.read();
    Serial.println(" ");
    Serial.println(val);

   if (val >= 0 && val <83){
       int led1pos = val;
       led1pos = map(led1pos, 0, 82, 0, 255);
       Serial.println("led1");
       Serial.println(led1pos);
       analogWrite(led1,led1pos);}
       
   if (val >= 82 && val <167){
       int led2pos = val;
       led2pos = map(led2pos, 83, 166, 0, 255);
       Serial.println("led2");
       Serial.println(led2pos);
       analogWrite(led2,led2pos);}
       
   if (val >= 166 && val <249){
       int led3pos = val;
       led3pos = map(led3pos, 167, 248, 0, 255);
       Serial.println("led3");
       Serial.println(led3pos);
       analogWrite(led3,led3pos);}
  }}

  /*--------------------V1.0------------------------
    if (val >= 82 || val <= 00){
        Serial.println("-");}
     else {
       val = map(val, 0, 82, 0, 255);
    Serial.println("led1");
        Serial.println(val);}

    if (val >= 166 || val <= 83){
         Serial.println("-");}
      else {
        val = map(val, 83, 166, 0, 255);
        Serial.println("led2");
        Serial.println(val);}

    if (val >= 248 || val <= 167){
         Serial.println("-");}
      else {
        val = map(val, 167, 248, 0, 255);
        Serial.println("led3");
        Serial.println(val);} */
