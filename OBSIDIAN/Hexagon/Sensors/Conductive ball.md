During the hexagon exercise we will be using the conductivity of the steel ball bearings to our advantage, and create simple but reliable sensors by using the them to complete a circuit. 

On the following pictures the wiring is showcased: 
On the first two pictures, you can see that we need 3 wires for this sensor. One for the 3.3V powersource, one for the ground, and one for sensing. In case we wanted to have multiple sensors for the same microcontroller, we would only need another wire attached to a different sensor pin. A wiring for 2 sensors will be shown in the end.

The dark purple wire is connected to the 3.3V output, the black one to the ground and the orange one to the input pin.
![[photo_2021-08-24 12.55.09.jpeg]]
![[photo_2021-08-24 12.55.07.jpeg]]

On the following picture, we can see the wiring on the breadboard. The purple wire connects to the bright red wire, which will be one part of the sensor. The blue wire connects to the ground through a 1MOhm resistor and also to the orange wire which detects the voltage. The circuit is not complete, until the red and blue wires are connected, while this is the case, the input pin reads 0V, as we complete the circuit the input pin will read 3.3Vs, this will be the case, when the ball is in place as we can see in the next pictures.

![[photo_2021-08-24 12.55.02.jpeg]]

This is the default state of the sensor, when the two wires are not connected.

![[photo_2021-08-24 12.55.05.jpeg]]

Here the wires are connected, because the ball conducts electricity.
