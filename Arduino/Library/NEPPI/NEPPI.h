#ifndef NEPPI_h
#define NEPPI_h

#include "Arduino.h"
#include "Stepper.h"
#include "ESP32Servo.h"
#include "WiFi.h"
#include "ArduinoWebsockets.h"
#include "ESP32AnalogRead.h"


class NEPPI
{
   public:
   NEPPI();
    void step(Stepper _stepper, int nrsteps, int speed, int delnum);
    void servo(Servo _servo, int posinit, int posend, int delnum);
  private:
  

};
#endif
