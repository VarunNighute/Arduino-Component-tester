#include "diode_led.h"
#include <Arduino.h>
#include "display.h"

const int diodePin = A3;
const float Vin = 5.0;

void measureDiode(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring...");
  delay(500);

  int raw = analogRead(diodePin);
  float voltage = (raw * Vin) / 1023.0;

  lcd.clear();
  lcd.setCursor(0,0);
  if(voltage > 0.2){
    lcd.print("Diode: ");
    if(voltage < 0.4) lcd.print("Ge");
    else if(voltage < 0.8) lcd.print("Si");
    else if(voltage > 3.3) lcd.print("Zener");
    else lcd.print("Unknown");
    lcd.setCursor(0,1);
    lcd.print("V:");
    lcd.print(voltage,2);
    lcd.print("V");
  } else{
    lcd.print("Diode: None");
    lcd.setCursor(0,1);
    lcd.print("Not connected");
  }
  delay(2000);
}

void measureLED(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring...");
  delay(500);

  int raw = analogRead(diodePin);
  float voltage = (raw * Vin)/1023.0;

  lcd.clear();
  lcd.setCursor(0,0);
  if(voltage > 0.2){
    lcd.print("LED: ");
    if(voltage>=1.7 && voltage<=2.0) lcd.print("Red");
    else if(voltage>2.0 && voltage<=2.4) lcd.print("Yellow");
    else if(voltage>2.4 && voltage<=3.5) lcd.print("Blue");
    else lcd.print("Unknown");
    lcd.setCursor(0,1);
    lcd.print("V:");
    lcd.print(voltage,2);
    lcd.print("V");
  } else{
    lcd.print("LED: None");
    lcd.setCursor(0,1);
    lcd.print("Not connected");
  }
  delay(2000);
}
