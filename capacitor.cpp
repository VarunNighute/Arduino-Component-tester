#include "capacitor.h"
#include <Arduino.h>
#include "display.h"

const int capacitorPin = A2;
const int chargePin = 13;
const int dischargePin = 9;
const float capacitorResistor = 10000;

void measureCapacitor(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring...");
  delay(500);

  unsigned long startTime, elapsedTime;
  float capacitance;

  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);
  delay(500);
  pinMode(dischargePin, INPUT);

  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, HIGH);
  startTime = millis();

  while(analogRead(capacitorPin) < 646){}  

  elapsedTime = millis() - startTime;
  digitalWrite(chargePin, LOW);
  pinMode(chargePin, INPUT);

  capacitance = (float)elapsedTime / (capacitorResistor * 1000.0);

  lcd.clear();
  lcd.setCursor(0,0);
  if(capacitance > 1e-6){
    lcd.print("Capacitance:");
    lcd.setCursor(0,1);
    lcd.print(capacitance * 1e6,2);
    lcd.print(" uF");
  } else {
    lcd.print("Capacitance:");
    lcd.setCursor(0,1);
    lcd.print(capacitance * 1e9,2);
    lcd.print(" nF");
  }

  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);
  delay(500);
  pinMode(dischargePin, INPUT);
}
