
#include <Wire.h>
#include <ArduinoNunchuk.h>

ArduinoNunchuk nunchuk = ArduinoNunchuk();
int m1_speed;
int m2_speed;

void setup() {
  Serial.begin(9600);
  nunchuk.init();   //Initialiser la Nunchuck
}

void loop() {

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

  x = nunchuk.analogX;
  y = nunchuk.analogY;

/*  if (x == X_ORIGN)
  {
    if (y )
  }
  else
  {
    
  }*/
    
}
