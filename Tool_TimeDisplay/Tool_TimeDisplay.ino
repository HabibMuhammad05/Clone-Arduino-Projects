#include <TimeLib.h>
#define TIME_REQUEST  7    

void setup() {
  Serial.begin(9600);
  setSyncProvider( requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
}

void loop() {
  PrintClock();
  delay(1000);
}

void PrintClock(){
    if (Serial.available()) {
    processSyncMessage();
  }
  if (timeStatus()!= timeNotSet) {
    digitalClockDisplay();  
  }
  if (timeStatus() == timeSet) {
    digitalWrite(13, HIGH); // LED on if synced
  } else {
    digitalWrite(13, LOW);  // LED off if needs refresh
  }
}
void digitalClockDisplay(){
  int Hours = hour();
  int Minutes = minute();
  int Seconds = second();
  int Days = day();
  int Months = month();
  int Years = year();
  String HourFormat = (Hours < 10 ? "0" : "") + String(Hours) + ":" + (Minutes < 10 ? "0" : "") + String(Minutes) + ":" + (Seconds < 10 ? "0" : "") + String(Seconds);
  String DateFormat = (Days < 10 ? "0" : "") + String(Days) + "/" + (Months <10 ? "0" : "") + String(Months) + "/"+ (Years < 10 ? "0" : "") + String(Years);
  Serial.print("Hour: "); Serial.print(HourFormat);
  Serial.print("   Date: "); Serial.println(DateFormat);


}

void processSyncMessage() {
  if(Serial.find("T")) {
     unsigned long pctime = Serial.parseInt();
     if( pctime >= 1357041600) { // epoch Jan 1 2013  check the integer is a valid time (greater than Jan 1 2013)
       setTime(pctime); // Sync Arduino clock to the time received on the serial port
     }
  }
}

time_t requestSync(){
  Serial.write(7);  // ASCII bell character requests a time sync message 
  return 0; // the time will be sent later in response to serial mesg
}



//  Serial.print("     Date: "); Serial.print(day());
//  Serial.print(",");  Serial.print(month());
//  Serial.print(",");  Serial.println(year()); 

//  Serial.print((Hours < 10 ? "0" : "") + String(Hours) + ":" + (Minutes < 10 ? "0" : "") + String(Minutes) + ":" + (Seconds < 10 ? "0" : "") + String(Seconds));
//  Serial.print(":");      Serial.print((Minutes < 10 ? "0" : "") + String(Minutes));
//  Serial.print(":");      Serial.print((Seconds < 10 ? "0" : "") + String(Seconds));
  

//  printDigits(minute());
//  printDigits(second());
//void printDigits(int digits){
//  // utility function for digital clock display: prints preceding colon and leading 0
//  lcd.print(":");
//  if(digits < 10)
//    lcd.print('0');
//  lcd.print(digits);
//}
