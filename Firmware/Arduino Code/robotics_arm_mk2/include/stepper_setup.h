/* 
Filename: stepper_setup.h
Purpose: Define the stepper motor objects, stepper motor pin setup, endstop switch setup,
and implementation of basic moveto, homing, acceleration modification functions. 


*/
#include <AccelStepper.h>


#ifndef __STEPPER_SETUP__
#define __STEPPER_SETUP__




extern AccelStepper XMOTOR();
extern AccelStepper YMOTOR();
extern AccelStepper ZMOTOR();

void pinsetup();

void autohome();

void xyhome();

void zhome();







#endif