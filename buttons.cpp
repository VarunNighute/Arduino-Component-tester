#include "buttons.h"
#include <Arduino.h>

const int nextButton = 0;
const int okButton = 10;

void pinSetup(){
  pinMode(nextButton, INPUT_PULLUP);
  pinMode(okButton, INPUT_PULLUP);
}

void handleButtons(int &mode, bool &testRunning){
  if(digitalRead(nextButton) == LOW){
    delay(300);
    mode = (mode + 1) % 8;
  }
  if(digitalRead(okButton) == LOW){
    delay(300);
    testRunning = !testRunning;
  }
}
