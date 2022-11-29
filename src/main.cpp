// Arduino Joystick controlled RC Car Project
// This Program is for the Joystick Module and RC Car movement (motors)

#include <Arduino.h>
#include <AFMotor.h> // AFMotor library, An Ada Fruit Library

// Defining Variables
// -------------------------------------------------------------------------------------------------------- //

// Defining input pins for the joystick module
#define x A0  // The X Analog Pin (VRX), corresponds to horizontal position or x-axis
#define y A1  // The Y Analog Pin (VRY), corresponds to vertical position or y-axis

// Defining the speed of the car
#define Speed 180 // Range from 0 to 255, 0 is off throttle while 255 represents full throttle

// Creating a AF_DCMotor object for each motor 
// first_motor uses terminal 3, motor second_motor uses terminal 4
// third_motor uses terminal 1, and fifth_motor uses terminal 2
AF_DCMotor first_motor(3);
AF_DCMotor second_motor(4);
AF_DCMotor third_motor(1);
AF_DCMotor fourth_motor(2);

void setup() {
  // put your setup code here, to run once:

  // begin the serial monitor
  Serial.begin(9600);

  // Setting up the speed for each DC Motor
  first_motor.setSpeed(Speed);
  second_motor.setSpeed(Speed);
  third_motor.setSpeed(Speed);
  fourth_motor.setSpeed(Speed);
}

// We get the analog values from the joystick module
void loop() {
  // put your main code here, to run repeatedly:

  // Both X and Y have analog values from 0 to 1023
  // These analog values correspond to the position of the joystick along either the x or y axis
  // The X and Y coordinates of the joystick together create a 2 coordinate system with the joystick
  // at rest being the center of the grid 
  
  int X = analogRead(x);  // reading value from the VRX input pin 
  int Y = analogRead(y);  // reading value from the VRY input pin

  // Printing values to console for testing 
  Serial.print(X);
  Serial.print("\t");
  Serial.println(Y);

  // Checking values 
  // The car moves depending on the analog values that are inputted on the joystick
  if (X >= 800) { // if X >= 800, the car moves forwards

    first_motor.run(BACKWARD);
    second_motor.run(BACKWARD);
    third_motor.run(BACKWARD);
    fourth_motor.run(BACKWARD);

  } else if ( X <= 200) {   // if X <= 200, the car moves backwards

    first_motor.run(FORWARD);
    second_motor.run(FORWARD);
    third_motor.run(FORWARD);
    fourth_motor.run(FORWARD);

  } else if (Y >= 800) {   // if Y >= 800, the car will turn left

    first_motor.run(FORWARD);
    second_motor.run(BACKWARD);
    third_motor.run(FORWARD);
    fourth_motor.run(BACKWARD);

  } else if (Y <= 200) {  // if Y <= 200, the car will turn right

    first_motor.run(BACKWARD);
    second_motor.run(FORWARD);
    third_motor.run(BACKWARD);
    fourth_motor.run(FORWARD);

  } else {  // When we are not turning the joystick in any direction

    first_motor.run(RELEASE);
    second_motor.run(RELEASE);
    third_motor.run(RELEASE);
    fourth_motor.run(RELEASE);

  }
}