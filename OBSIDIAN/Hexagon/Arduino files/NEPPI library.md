The NEPPI library consists of three files, two headers: NEPPI.h and NEPPI_Info.h and a C++ script: NEPPI.cpp.

The NEPPI.h file describes the 

Adding the NEPPI library to the "Arduino/libraries" folder will grant access to the use of the NEPPI class and the NEPPI_Info.h header file.

After creating a NEPPI object(in this case it will have the name neppi), we can utilize the two functions that it has: step and servo.

1. servo
	This function takes 4 arguments, a Servo object and 3 integers: the initial and end position, both are between 0 and 180, and the third is the delay between two positions in milliseconds.
	neppi.servo(Servo _servo, int initpos, int endpos, int delnum);
2. step
	This function also takes 4 arguments, a Stepper object and 3 integers: the number of steps we want the stepper to make, the speed of the stepper, and a possible delay after the steps were taken.
	neppi.step(Stepper _stepper, int nrsteps, int speed, int delnum);