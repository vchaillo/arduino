#include <Arduino.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 9600

ArduinoNunchuk nunchuk = ArduinoNunchuk();
const int led = 2;
const int relais = 4;

int state = LOW;
bool push_z = true;
bool push_c = true;

void setup()
{
  Serial.begin(BAUDRATE);
  pinMode(led, OUTPUT);
  pinMode(relais, OUTPUT);
  nunchuk.init();   // Initialiser le nunchuck
}

void loop()
{
  nunchuk.update();  // lecture des donnees
  
  if (nunchuk.zButton == 1)
  {
    if (!digitalRead(led) && push_z == false)
      digitalWrite(led, HIGH);
    else if (push_z == false)
      digitalWrite(led, LOW);
    push_z = true;
  }
  else
    push_z = false;

  if (nunchuk.cButton == 1)
  {
    if (!digitalRead(relais) && push_c == false)
      digitalWrite(relais, HIGH);
    else if (push_c == false)
      digitalWrite(relais, LOW);
    push_c = true;
  }
  else
    push_c = false;

  // Impression des valeurs du nunchuk
  // Joystick XY
  Serial.print(nunchuk.analogX, DEC);  // 0-255 X, 125 au neutre
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  // Accelerometre XYZ
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  // Boutons c et z
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);

}
