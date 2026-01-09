#include "continuity.h"
#include <Arduino.h>
#include "display.h"

const int diodePin = A3;
const float Vin = 5.0;

void continuityTester(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring...");
  delay(500);

  int raw = analogRead(diodePin);
  float voltage = (raw*Vin)/1023.0;

  lcd.clear();
  lcd.setCursor(0,0);
  if(voltage>=4.9) lcd.print("Open Circuit");
  else lcd.print("Short Circuit");

  delay(2000);
}
