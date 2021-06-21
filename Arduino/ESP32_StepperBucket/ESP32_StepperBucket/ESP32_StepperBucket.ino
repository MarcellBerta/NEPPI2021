#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 0, 4, 16);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  myStepper.setSpeed(100);
}

void loop() {
Serial.println("clockwise");
  myStepper.step(stepsPerRevolution*20);
  delay(50);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution*20);
  delay(50);
    
    
}
