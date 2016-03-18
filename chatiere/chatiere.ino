#include <Servo.h>

#define OPEN 180
#define CLOSE 80
#define GREEN 2
#define RED 3

Servo servo;
int detect = 0;

void init_blink()
{
  int i = 0;
  while (i < 3)
  {
    digitalWrite(GREEN, HIGH);
    delay(100);
    digitalWrite(GREEN, LOW);
    delay(100);
    i++;  
  }
  delay(500);
  digitalWrite(RED, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  servo.attach(9);
  servo.write(CLOSE);
  delay(500);
  init_blink();
}

// the loop function runs over and over again forever
void loop() {
  detect = analogRead(A0);
  Serial.println(detect);
  
  if (detect)
  {
    servo.write(OPEN);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    delay(3000);
  }    
  else
  {
    servo.write(CLOSE);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    delay(500);
  }
}
