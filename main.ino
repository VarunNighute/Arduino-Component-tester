#include <Arduino.h>
#include "display.h"
#include "buttons.h"
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"
#include "diode_led.h"
#include "bjt.h"
#include "continuity.h"
#include "ldr.h"

int mode = 0;
bool testRunning = false;

void setup() {
  Serial.begin(9600);
  lcdBegin();
  pinSetup();
  showMenu(mode);
}

void loop() {
  handleButtons(mode, testRunning);
  if(testRunning){
    runTest(mode);
  }
}

void runTest(int mode){
  switch(mode){
    case 0: measureResistor(); break;
    case 1: measureInductor(); break;
    case 2: measureCapacitor(); break;
    case 3: measureDiode(); break;
    case 4: measureLED(); break;
    case 5: measureBJT(); break;
    case 6: continuityTester(); break;
    case 7: measureLDR(); break;
  }
}
