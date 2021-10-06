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
    void step(Stepper _stepper, int nrsteps, int speed, int delnum = 0);
   
    // Servo doesn't work due to "timer stuff"
    //void servo(Servo _servo, int posinit, int posend, int delnum);
  private:
  

};
#endif
