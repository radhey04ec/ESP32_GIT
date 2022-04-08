
/*   Program LED Blink
 *   Baord : ESP32 V1.0 REV1 WIFI BLUETOOTH LITE (Lolin-32)
 *   Built in LED is on GPIO-22
 *   Jaydeep Shah - 7 April 22
 */

 
#define LED_BUILTIN 22    //Built in LED


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
