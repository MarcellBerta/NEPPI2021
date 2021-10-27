#include <WiFiPass.h>
#include <NEPPI.h>

/*
  Secured Esp32 Websockets Client
  This sketch:
        1. Connects to a WiFi network
        2. Connects to a Websockets server (using WSS)
        3. Sends the websockets server a message ("Hello Server")
        4. Sends the websocket server a "ping"
        5. Prints all incoming messages while the connection is open
    NOTE:
    The sketch dosen't check or indicate about errors while connecting to 
    WiFi or to the websockets server. For full example you might want 
    to try the example named "Esp32-Client" (And use the ssl methods).
  Hardware:
        For this sketch you only need an Esp32 board.
  Created 15/02/2019
  By Gil Maimon
  https://github.com/gilmaimon/ArduinoWebsockets
*/

#include <ArduinoWebsockets.h>
#include <WiFi.h>
#include <ESP32Servo.h>
NEPPI neppitest;
Servo myservo;
const char* ssid = NEPPI_SSID;
const char* password = NEPPI_PASS; 
const char* websockets_connection_string = NEPPI_SOCKET; 
const char echo_org_ssl_ca_cert[] PROGMEM = NEPPI_CERTIFICATE;

int outPin = 5;
int inPin = 18;
int val = LOW;

using namespace websockets;

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

WebsocketsClient client;

void setup() {
    Serial.begin(115200);
    
    pinMode(outPin, OUTPUT);
    pinMode(inPin, INPUT);
    // Connect to wifi
    WiFi.begin(ssid, password);

    // Wait some time to connect to wifi
    for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(1000);
    }

    // run callback when messages are received
    client.onMessage(onMessageCallback);
    
    // run callback when events are occuring
    client.onEvent(onEventsCallback);

    // Before connecting, set the ssl fingerprint of the server
    client.setCACert(echo_org_ssl_ca_cert);

    // Connect to server
    client.connect(websockets_connection_string);

    // Send a message
    String bootingmsg = "booting," + WiFi.macAddress();
    client.send(bootingmsg);
    client.send("paths,0-2:1-3");

    // Send a ping
    client.ping();
}

void loop() {
    client.poll();
    
}
