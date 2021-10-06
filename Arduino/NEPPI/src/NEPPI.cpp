#include "Arduino.h"
#include "NEPPI.h"
#include "Stepper.h"
#include "ESP32Servo.h"
NEPPI :: NEPPI ()
{
    
    
}

void NEPPI :: step(Stepper _stepper, int nrsteps, int speed, int delnum = 0)
{
    _stepper.setSpeed(speed);
    _stepper.step(nrsteps);
    delay(delnum);
}

// Servo func does not work due to "timer stuff"
/*
void NEPPI :: servo(Servo _servo, int posinit, int posend, int delnum)
{
    int pos;
    if (posinit < posend)
    {
        for (pos = posinit; pos <= posend; pos += 1) 
        { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(delnum);             // waits 15ms for the servo to reach the position
	    }
    }
    else
    {
        for (pos = posinit; pos >= posend; pos -= 1) 
        { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(delnum);             // waits 15ms for the servo to reach the position
	    }
    }
    
}
*/
