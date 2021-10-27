#include <WiFi.h>

const char* ssid = "aalto open"; 
const char* password = ""; 

void setup(){
  Serial.begin(115200);
  
  Serial.println();
  Serial.print("ESP Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
}
 
void loop(){

}
