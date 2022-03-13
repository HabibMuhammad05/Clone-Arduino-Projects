#include <NewPing.h>

#define TRIGGER_PIN 12 // Arduino pin untuk trigger pin ultrasonic sensor.
#define ECHO_PIN 11 // Arduino pin untuk echo pin ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  int cm = sonar.ping_cm(); // Send out the ping, get the results in centimeters.
  Serial.print("Ping: ");
  Serial.print(cm); // Print the result (0 = outside the set distance range, no ping echo)
  Serial.println("cm");
}

