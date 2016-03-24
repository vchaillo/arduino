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

#define ON 0
#define OFF 1

float time = 83.33;
int btn = 13;
int onoff = OFF;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT);
  int pin = 2;
  while (pin < 8)
  {
    pinMode(pin, OUTPUT);
    pin++;
  }
}

// the loop function runs over and over again forever
void loop() {
  int btn_state = digitalRead(btn);
  Serial.println(btn_state);
  if (btn_state == LOW)
  {
    if (onoff == OFF)    
      onoff = ON;
    else
      onoff = OFF;
  }
  
  if (onoff == ON)
  { 
    int led = 2;
    while (led < 8)
    {
      digitalWrite(led, HIGH);
      delay(time);
      led++;
    }
    led = 7;
    while (led > 1)
    {
      digitalWrite(led, LOW);
      delay(time);
      led--;
    }
  }
}
