# NEPPI2021 GitHub

## Welcome to the 2021 NEPPI course Github
Welcome to the GitHub site for the NEPPI course! Here you can find all the necessary files to start programming your ESP32.
## Section 1: What is in the kit?
Hexagon components: A base, a middle part and a top, 6 pillars, 2-4 walls and accessories for those walls.\
Electronic components: Ten wires of each type, 1MOhm resistors, a stepper motor, a stepper controller, an ESP32, a micro-USB to USB able, two servos, a breadboard, a battery and a clip.\
Other: A steel ball.
## Section 2: Installing Arduino IDE and the necessary libraries
The first thing that needs to be installed is the Arduino Dekstop IDE. Which will compile and upload your code to the microncontroller (in our case an ESP32. You can find the installation guide in the following link \
Arduino IDE installation guide: https://www.arduino.cc/en/Guide (Scroll down to the Install the Arduino Desktop IDE section) \
Next, we will have to install the ESP32 library so that we can upload scripts to the ESP32s.https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/ \
Next up, we will be installing 5 public and 1 custom library and we are ready to go. The public libraries are as follows: WiFi (by Arduino), Stepper (by Arduino), ESP32AnalogRead (by Kevin Harrington), ESP32Servo (by Kevin Harrington) and ArduinoWebsockets (by Gil Maimon). You can install all of these libraries through the IDE itself, by using the "Manage libraries" tab as shown below: \
<img width="860" alt="Screenshot 2021-11-01 at 13 58 04" src="https://user-images.githubusercontent.com/64134220/139672737-2c515d3d-9489-483f-af59-d7eae4b29c95.png">

<img width="798" alt="Screenshot 2021-11-01 at 13 56 45" src="https://user-images.githubusercontent.com/64134220/139672705-5946f811-cae6-43ea-88b2-d1fb84ecc366.png">
<img width="799" alt="Screenshot 2021-11-01 at 13 59 06" src="https://user-images.githubusercontent.com/64134220/139673380-16037eea-b51c-4ecb-b1c7-06725b3c1881.png">
<img width="802" alt="Screenshot 2021-11-01 at 13 59 38" src="https://user-images.githubusercontent.com/64134220/139673390-6a337038-8929-49ba-bcf4-63761d0d10f1.png">
<img width="805" alt="Screenshot 2021-11-01 at 14 00 41" src="https://user-images.githubusercontent.com/64134220/139673420-2f68aaa8-a878-40b5-9c64-3ef0df0ac88d.png">
<img width="799" alt="Screenshot 2021-11-01 at 14 05 23" src="https://user-images.githubusercontent.com/64134220/139673431-12eb2792-42bf-4810-b1a8-3780222bc7c4.png">

Each library has some example sketches that you can check out under File->Examples. \
Finally we have our own library "NEPPI". You can install it by downloading the contents of this github and copying the NEPPI folder found in he Library folder to your own library folder in your Arduino folder on your computer. You can read more about how to install custom libraries here: *insert link* \
Since the NEPPI library includes all libraries we only need to include the NEPPI library in our code to access all of them. You can find out more about the NEPPI library in the documentations section. \
## Section 3: Documentations
### Section 3.1: Documentation for the parts
Stepper:
Stepper controller:
Servo:https://media.digikey.com/pdf/Data%20Sheets/DFRobot%20PDFs/SER0043_Web.pdf \
Resistors:
ESP32:

