/* 
Filename: stepper_setup.h
Purpose: Define the stepper motor objects, stepper motor pin setup, endstop swtich setup,
and implementation of basic moveto, homing, accleration modification functions. 


*/


#ifndef __STEPPER_SETUP__
#define __STEPPER_SETUP__



void pinsetup();

void autohome();

void xyhome();

void zhome();







#endif