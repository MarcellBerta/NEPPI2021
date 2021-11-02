/*
 This is the starting sketch for Aalto's NEPPI 2021 course. You will find a lot of
 code that you need not to worry about. However all lines will be explained, so if 
 you are interested, feel free to take a look.

 The code consists of several sections, all of them are documented, if you feel confused,
 or have any questions about it, don't hesitate to ask the assistants for help.

 The sections are:
      1. Calling th necessary libraries
      2. Creating the necessary constant variables that are needed for the ESP32 to 
         connect to the internet and the websocket.
      3. Writing the necessary functions to create the connection with the webserver
      4. Creating the Servos, the stepper and the sensors. For this, you will have to
         enter the pins that you are using for these.
      5. Setting up the websocket connection
      6. The rest of the setup function depends on what you would like to use it for.
         You can enter the functions that you would like the ESP32 to do once, when it
         boots.
      7. The loop function is called over and over again, you can put your code here
         that you would like to run constantly.
      8. If you feel that it is necessary, you can create new functions here that you
         may use in the setup and loop functions. Anything you create has to be called
         in either of those funcitons, since the ESP32 will only excecute them.
 */
 
  // Section 1:
 
#include <NEPPI_Info.h> //This is the header file, containing the information for the wifi and webserver
#include <NEPPI.h> //This library is created for this course, it contains all the necessary libraries and the step and servo functions
#include <ESP32Servo.h>

using namespace websockets;

  // Section 2:

//These values are from the WiFiPass header file

const char* ssid = "DSDnternet"; //This is the name of the WiFi
const char* password = "MEGArareDSDxperience42069"; //This is the password of the WiFi
const char* websockets_connection_string = NEPPI_SOCKET; //This is the URL of the Websocket
const char echo_org_ssl_ca_cert[] PROGMEM = NEPPI_CERTIFICATE; //This is the https certificate for the Websocket
NEPPI neppi;
ESP32AnalogRead adc;
WebsocketsClient client;
int ID = 2;
  // Section 3:
//These two functions are used to react to incoming messages and events
void onMessageCallback(WebsocketsMessage message) {
    Serial.print("Got Message: ");
    Serial.println(message.data());
    
}

void onEventsCallback(WebsocketsEvent event, String data) {
    if(event == WebsocketsEvent::ConnectionOpened) {
        Serial.println("Connnection Opened");
    } else if(event == WebsocketsEvent::ConnectionClosed) {
        Serial.println("Connnection Closed");
    } else if(event == WebsocketsEvent::GotPing) {
        Serial.println("Got a Ping!");
    } else if(event == WebsocketsEvent::GotPong) {
        Serial.println("Got a Pong!");
    }
}


  // Section 4
int stepsPerRevolution = 200; // This is the steps the stepper needs to make a full revolution
int stepperIn1 = 4; //The pin to which In1 on the driver is connected
int stepperIn2 = 16; //The pin to which In2 on the driver is connected
int stepperIn3 = 17; //The pin to which In3 on the driver is connected
int stepperIn4 = 5; //The pin to which In4 on the driver is connected
Stepper myStepper(stepsPerRevolution, stepperIn1, stepperIn2, stepperIn3, stepperIn4); //This creates he myStepper object

Servo myServo1;
Servo myServo2;
void setup() {
  // Section 5
myServo1.attach(23,1000,2000);
myServo1.setPeriodHertz(60);


  Serial.begin(115200); // The ESP32 will start communcation with the Serial monitor on Baud 115200
  // The timers allocated here will be used for controlling the Servos
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  // The ESP32 connects to the wifi and informs the serial monitor
  WiFi.begin(ssid,password);
  for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(1000);
  }
  // The ESP32 will start listening for messages and events, using the functions defined above
  client.onMessage(onMessageCallback);
  client.onEvent(onEventsCallback);
  //The ESP32 connects to the websocket and sends the certificate
  client.setCACert(echo_org_ssl_ca_cert);
  client.connect(websockets_connection_string);
  // The ESP32 sends the booting message, letting the websocket know its MAC address for identification
  String bootmsg = "booting," + WiFi.macAddress() + ","+ID;
  client.send(bootmsg);

  client.send("gates,1235");
  
  
  // Section 6 : put your setup code here, to run once
  
}
int pos;
void loop() {

for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo1.write(pos);    // tell servo to go to position in variable 'pos'
    delay(15);             // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myServo1.write(pos);    // tell servo to go to position in variable 'pos'
    delay(15);             // waits 15ms for the servo to reach the position
  }



  client.poll(); //The ESP32 pings the websocket to maintain conneciton
  // Section 7 : put your main code here, to run repeatedly:
}


  //Section 8 : you may write any functions that you would like to use inside the setup or loop functions
