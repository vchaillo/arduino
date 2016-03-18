#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 13, 5, 4, 3, 2);

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Alexandre pue du");
    lcd.setCursor(0, 1);
    lcd.print("trou de balle");
}

void loop()
{

}

