#include <Arduino.h>
#include "display.h"
#include "orzKeypad.h"
#include "calBehavior.h"

void setup()
{
  Serial.begin(9600);
  displayInit();
  showTest();
  Serial.println("START!");
  // put your setup code here, to run once:
}

void loop()
{
  char key = keypad.getKey();
  if (key)
  {
    cal(key);
    // Serial.println(key);
    // u8g2.firstPage();
    // do
    // {
    //   u8g2.setCursor(24, 24);
    //   u8g2.println(key);

    // } while (u8g2.nextPage());
  }
  // put your main code here, to run repeatedly:
}