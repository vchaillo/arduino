#include <IRremote.h>

const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
IRsend irsend;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
  {
    if (results.decode_type == NEC)
      Serial.println("NEC : ");
    if (results.decode_type == SONY)
      Serial.println("SONY : ");
    if (results.decode_type == RC5)
      Serial.println("RC5 : ");
    if (results.decode_type == RC6)
      Serial.println("RC6 : ");
    if (results.decode_type == UNKNOWN)
      Serial.println("UNKNOWN : ");
      
    Serial.println(results.value, HEX);

    if (results.value == 0x8AF13528)
    {
      irsend.sendRC5(0x54C, 12);
      irsend.sendRC5(0xD4C, 12);
      Serial.println("ON OFF");
      delay(50);
    }

    irrecv.enableIRIn();
    irrecv.resume();
  }
  delay(500);
}
