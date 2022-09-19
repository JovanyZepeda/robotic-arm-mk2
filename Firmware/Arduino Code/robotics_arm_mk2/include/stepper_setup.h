/* 
Filename: stepper_setup.h
Purpose: Define the stepper motor objects, stepper motor pin setup, endstop switch setup,
and implementation of basic moveto, homing, acceleration modification functions. 


*/
#include <AccelStepper.h>


#ifndef __STEPPER_SETUP__
#define __STEPPER_SETUP__


#define XSTEP 2 //Stepper Motor Step pin
#define YSTEP 3
#define ZSTEP 4
#define XDIR 5 // Stepper motor Direction control pin
#define YDIR 6
#define ZDIR 7
#define ENABLE 8 // CNC Shield Enable Pin
#define XLIMIT 9 // Limit switch pins
#define YLIMIT 10
#define ZLIMIT 11
#define XMOTORACC 250 // Acceleration and Max Speed values
#define XMOTORMAXSPEED 1000
#define YMOTORACC 250
#define YMOTORMAXSPEED 1000

extern AccelStepper XMOTOR;
extern AccelStepper YMOTOR;
extern AccelStepper ZMOTOR;

void pinsetup();

void autohome();

void xyhome();

void zhome();







#endif