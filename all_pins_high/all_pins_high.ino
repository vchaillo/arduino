void setup() {
  // put your setup code here, to run once:
  int pin = 0;

  while (pin < 14)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    pin++;  
  }
}

void loop() {

}
