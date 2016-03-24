/*
 * ArduinoNunchukDemo.ino
 *
 * Copyright 2011-2013 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 *
 */

#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 9600

ArduinoNunchuk nunchuk = ArduinoNunchuk();
int led = 4;
int relais = 2;
int buz = 7;

void setup()
{
  Serial.begin(BAUDRATE);
  pinMode(led, OUTPUT);
  pinMode(relais, OUTPUT);
  nunchuk.init();   //Initialiser la Nunchuck
}

void loop()
{
  nunchuk.update();  //lecture des donnees
  //Joystick XY
  Serial.print(nunchuk.analogX, DEC);  //0-255 X, 125 au neutre
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  
  //Accelerometre XYZ
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  
  //Deux boutons de la Nunchuck Wii
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);

  if (nunchuk.zButton == 1)
  {
    digitalWrite(led, HIGH);
    digitalWrite(relais, HIGH);
    //tone(buz, 50, 50);
    //tone(buz, 0, 50);
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(relais, LOW);
  }
}
