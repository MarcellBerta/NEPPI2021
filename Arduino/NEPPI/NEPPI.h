#ifndef NEPPI_h
#define NEPPI_h

#include "Arduino.h"
#include "Stepper.h"
#include "ESP32Servo.h"
#include "WiFi.h"
#include "ArduinoWebsockets.h"

class NEPPI
{
   public:
   NEPPI();
    void step(Stepper _stepper, int nrsteps, int speed, int delnum);
   
    // servo caused problems commented due to "timer errors"
    //void servo(Servo _servo, int posinit, int posend, int delnum);
  private:
  

};
#endif
