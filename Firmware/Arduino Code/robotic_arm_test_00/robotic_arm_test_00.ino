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
#include <AccelStepper.h>
AccelStepper XMOTOR(1,XSTEP,XDIR);
AccelStepper YMOTOR(1,YSTEP,YDIR);
AccelStepper ZMOTOR(1,ZSTEP,ZDIR);

void pinsetup(){
   pinMode(ENABLE,OUTPUT);
   digitalWrite(ENABLE,LOW);
   pinMode(XLIMIT,INPUT_PULLUP);
   pinMode(YLIMIT,INPUT_PULLUP);
   pinMode(ZLIMIT,INPUT_PULLUP);
}

void autohome(){ //We're using this to call our homing routine 
   xyhome();
   zhome();
}
void xyhome() {
   int initial_xhome = -1;
   int initial_yhome = -1;
   // Set Max Speed and Acceleration of each Steppers at startup for homing
   XMOTOR.setMaxSpeed(500.0); // Set Max Speed of Stepper (Slower to get better accuracy)
   XMOTOR.setAcceleration(50.0); // Set Acceleration of Stepper
   YMOTOR.setMaxSpeed(500.0); // Set Max Speed of Stepper (Slower to get better accuracy)
   YMOTOR.setAcceleration(50.0); // Set Acceleration of Stepper
   // Start Homing procedure of Stepper Motor at startup
   while (digitalRead(YLIMIT)) { // Make the Stepper move CCW until the switch is activated
   XMOTOR.moveTo(initial_xhome); // Set the position to move to
   YMOTOR.moveTo(initial_yhome); // Set the position to move to
   initial_xhome--; // Decrease by 1 for next move if needed
   initial_yhome--;
   XMOTOR.run(); // Start moving the stepper
   YMOTOR.run();
   delay(5);
 }
   XMOTOR.setCurrentPosition(0); // Set the current position as zero for now
   YMOTOR.setCurrentPosition(0);
   initial_xhome = -1;
   initial_yhome = 1;
   while(digitalRead(XLIMIT)){
   XMOTOR.moveTo(initial_xhome); // Set the position to move to
   YMOTOR.moveTo(initial_yhome); // Set the position to move to
   initial_xhome--; // Decrease by 1 for next move if needed
   initial_yhome++;
   XMOTOR.run(); // Start moving the stepper
   YMOTOR.run();
   delay(5);
 }
 YMOTOR.setCurrentPosition(0); // Set the current position as zero for now
 YMOTOR.setMaxSpeed(250.0); // Set Max Speed of Stepper (Slower to get better accuracy)
 YMOTOR.setAcceleration(10.0); // Set Acceleration of Stepper
 initial_yhome = 1;
 while (!digitalRead(YLIMIT)) { // Make the Stepper move CW until the switch is deactivated
 YMOTOR.moveTo(initial_yhome);
 YMOTOR.run();
 initial_yhome++;
 delay(5);
 }
 YMOTOR.setCurrentPosition(0);
 YMOTOR.setMaxSpeed(YMOTORMAXSPEED); // Set Max Speed of Stepper (Faster for regular movements)
 YMOTOR.setAcceleration(YMOTORACC); // Set Acceleration of Stepper
 XMOTOR.setCurrentPosition(0); // Set the current position as zero for now
 XMOTOR.setMaxSpeed(250.0); // Set Max Speed of Stepper (Slower to get better accuracy)
 XMOTOR.setAcceleration(10.0); // Set Acceleration of Stepper
 initial_xhome = 1;
 while (!digitalRead(XLIMIT)) { // Make the Stepper move CW until the switch is deactivated
 XMOTOR.moveTo(initial_xhome);
 XMOTOR.run();
 initial_xhome++;
 delay(5);
 }
 XMOTOR.setCurrentPosition(0);
 XMOTOR.setMaxSpeed(XMOTORMAXSPEED); // Set Max Speed of Stepper (Faster for regular movements)
 XMOTOR.setAcceleration(XMOTORACC); // Set Acceleration of Stepper
}
void zhome() {
 int initial_zhome = -1;
 // Set Max Speed and Acceleration of each Steppers at startup for homing
 ZMOTOR.setMaxSpeed(100.0); // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(100.0); // Set Acceleration of Stepper
 // Start Homing procedure of Stepper Motor at startup
 while (digitalRead(ZLIMIT)) { // Make the Stepper move CCW until the switch is activated
 ZMOTOR.moveTo(initial_zhome); // Set the position to move to
 initial_zhome--; // Decrease by 1 for next move if needed
 ZMOTOR.run(); // Start moving the stepper
 delay(5);
 }
 ZMOTOR.setCurrentPosition(0); // Set the current position as zero for now
 ZMOTOR.setMaxSpeed(50.0); // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(50.0); // Set Acceleration of Stepper
 initial_zhome = 1;
 while (!digitalRead(ZLIMIT)) { // Make the Stepper move CW until the switch is deactivated
 ZMOTOR.moveTo(initial_zhome);
 ZMOTOR.run();
 initial_zhome++;
 delay(5);
 }
 ZMOTOR.setCurrentPosition(0);
 ZMOTOR.setMaxSpeed(1000.0); // Set Max Speed of Stepper (Faster for regular movements)
 ZMOTOR.setAcceleration(1000.0); // Set Acceleration of Stepper
}


void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
 pinsetup();
// autohome();
 Serial.println("HOMING OK");
}


void loop() {
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
