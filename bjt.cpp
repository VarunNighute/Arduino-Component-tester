#include "bjt.h"
#include <Arduino.h>
#include "display.h"

const int nmosGate = 7;
const int pmosGate = 7;
const int bjtBase = 6;
const int bjtCollector = A5;
const int bjtEmitter = A4;
const float Vin = 5.0;

void measureBJT(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Testing...");
  delay(500);

  float Vb, Vc, Ib, Ic, hFE;

  digitalWrite(nmosGate,HIGH);
  digitalWrite(pmosGate,HIGH);
  digitalWrite(bjtBase,HIGH);
  delay(100);

  Vb = analogRead(bjtEmitter)*(Vin/1023.0);
  Vc = analogRead(bjtCollector)*(Vin/1023.0);

  if(Vb<0.2 && Vc<0.2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BJT Status:");
    lcd.setCursor(0,1);
    lcd.print("Not Connected");
    return;
  }

  Ib = (Vin-Vb)/10000.0;
  Ic = (Vin-Vc)/1000.0;
  hFE = Ic/Ib;

  if(hFE>1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BJT Type:");
    lcd.setCursor(0,1);
    lcd.print("NPN Transistor");
  } else{
    digitalWrite(nmosGate,LOW);
    digitalWrite(pmosGate,LOW);
    digitalWrite(bjtBase,LOW);
    delay(100);

    Vb = analogRead(bjtEmitter)*(Vin/1023.0);
    Vc = analogRead(bjtCollector)*(Vin/1023.0);

    if(Vb<0.2 && Vc<0.2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("BJT Status:");
      lcd.setCursor(0,1);
      lcd.print("Not Connected");
      return;
    }

    Ib = (Vb)/10000.0;
    Ic = (Vc)/1000.0;
    hFE = Ic/Ib;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BJT Type:");
    lcd.setCursor(0,1);
    lcd.print("PNP Transistor");
  }
}
