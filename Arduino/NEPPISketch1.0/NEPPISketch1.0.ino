#include <NEPPI.h>
#include <Arduino.h>
#include <WiFi.h>
#include <Stepper.h>

#include "WiFiPass.h"

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

//Write function for connecting to internet
// Function for communication with websocket

NEPPI neppi;
const char echo_org_ssl_ca_cert[] = NEPPICERT;

 
void setup() {
  
Serial.begin(115200);
Serial.println(echo_org_ssl_ca_cert);
  // Put your code here that you would only like to run once
}

void loop() {

  
  //Put your code here that you would like the ESP32 to excecute constantly

}
