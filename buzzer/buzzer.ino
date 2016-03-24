

char DIO_Buzzer = 7;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(DIO_Buzzer, 500, 50);
  delay(2000);
}
