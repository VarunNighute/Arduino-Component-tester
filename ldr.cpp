#include "ldr.h"
#include <Arduino.h>
#include "display.h"

const int resistorPin = A0;
const float Vin = 5.0;
const float R1 = 100000;
const int nextButton = 0;

void measureLDR(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LDR Resistance:");
  delay(1000);

  while(digitalRead(nextButton) != LOW){
    int raw = analogRead(resistorPin);
    float Vout = (raw*Vin)/1024.0;
    float R2 = (Vout>0)? R1*((Vin/Vout)-1):0;

    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    if(R2>0){
      lcd.print(R2,1);
      lcd.print(" Ohm");
    } else{
      lcd.print("Disconnected");
    }
    delay(500);
  }
}
