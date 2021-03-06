/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int   led = 8;
int   button = 2;
int   btn_state = NULL;
int   a = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  btn_state = digitalRead(button);

  if (a == 0 && btn_state == LOW)
  {
    a = 1;
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    
  }
  else if (a == 1 && btn_state == LOW)
  {
    a = 0;
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
  }
}
