#include "inductor.h"
#include <Arduino.h>
#include "display.h"

const int inductorPin = A1;
const int inductorCharge = 8;
const float inductorResistance = 1000.0;

void measureInductor(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring...");
  delay(500);

  unsigned long startTime, endTime;
  digitalWrite(inductorCharge,HIGH);
  delayMicroseconds(5);
  startTime = micros();
  while(analogRead(inductorPin) < 512);
  endTime = micros();
  digitalWrite(inductorCharge,LOW);

  float timeSeconds = (endTime-startTime)/1000000.0;
  float inductance = (inductorResistance*timeSeconds)/0.693;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Inductance:");
  lcd.setCursor(0,1);
  if(inductance>0){
    lcd.print(inductance*1000);
    lcd.print(" mH");
  } else{
    lcd.print("Error");
  }
}
