#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

void lcdBegin();
void showMenu(int mode);

#endif
