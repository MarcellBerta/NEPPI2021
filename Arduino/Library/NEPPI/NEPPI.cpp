#include "Arduino.h"
#include "NEPPI.h"
#include "Stepper.h"
#include "ESP32Servo.h"
#include "ArduinoWebsockets.h"
#include "ESP32AnalogRead.h"

NEPPI :: NEPPI ()
{
    
    
}

void NEPPI :: step(Stepper _stepper, int nrsteps, int speed, int delnum)
{
    _stepper.setSpeed(speed);
    _stepper.step(nrsteps);
    delay(delnum);
}


