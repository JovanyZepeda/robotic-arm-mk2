#include <Arduino.h>
#include "stepper_setup.h"

void setup() {
  // put your setup code here, to run once:
  pinsetup();
  
 XMOTOR.runToNewPosition(100);
 delay(1000);
 YMOTOR.runToNewPosition(50);
 delay(1000);
 YMOTOR.runToNewPosition(-50);
 delay(1000);
 YMOTOR.runToNewPosition(0);
 delay(1000);
 XMOTOR.runToNewPosition(0);
 delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}