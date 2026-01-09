#include "display.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void lcdBegin(){
  lcd.begin(16,2);
}

void showMenu(int mode){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Select Test:");
  lcd.setCursor(0,1);
  switch(mode){
    case 0: lcd.print("Resistor"); break;
    case 1: lcd.print("Inductor"); break;
    case 2: lcd.print("Capacitor"); break;
    case 3: lcd.print("Diode"); break;
    case 4: lcd.print("LED"); break;
    case 5: lcd.print("BJT"); break;
    case 6: lcd.print("Continuity"); break;
    case 7: lcd.print("LDR"); break;
  }
}
