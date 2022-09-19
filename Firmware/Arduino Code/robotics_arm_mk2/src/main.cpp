#include <Arduino.h>
#include "stepper_setup.h"
#include <AccelStepper.h>




void setup() {
  pinsetup();
  ZMOTOR.setMaxSpeed(150);
  XMOTOR.setMaxSpeed(150);
  YMOTOR.setMaxSpeed(150);

  ZMOTOR.setAcceleration(100);
  XMOTOR.setAcceleration(100);
  YMOTOR.setAcceleration(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  ZMOTOR.runToNewPosition(0);
  ZMOTOR.runToNewPosition(75);
  ZMOTOR.runToNewPosition(-75);
  ZMOTOR.runToNewPosition(0);

  XMOTOR.runToNewPosition(0);
  XMOTOR.runToNewPosition(35);
  XMOTOR.runToNewPosition(0);

  YMOTOR.runToNewPosition(0);
  YMOTOR.runToNewPosition(60);
  YMOTOR.runToNewPosition(0);
  
}