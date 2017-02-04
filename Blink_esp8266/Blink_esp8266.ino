/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
const short int LED_PIN1 = D0;//GPIO16
const short int LED_PIN2 = D4;//GPIO16

void setup() {

pinMode(LED_PIN1, OUTPUT); //GPIO16 is an OUTPUT pin;
digitalWrite(LED_PIN1, LOW); //Initial state is ON

pinMode(LED_PIN2, OUTPUT); //GPIO16 is an OUTPUT pin;
digitalWrite(LED_PIN2, LOW); //Initial state is ON

}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(LED_PIN1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(LED_PIN2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_PIN1, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
}
