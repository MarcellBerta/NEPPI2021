#include "Arduino.h"
#include <ESP32AnalogRead.h>
ESP32AnalogRead adc;


void setup()

{
	adc.attach(25);
	Serial.begin(115200);

}

void loop()
{
 
	Serial.println("Voltage = "+String(adc.readVoltage()));


  delay(50);
}
