// Servo Motor Control using Joystick Module (5 pins) with Arduino Nano
// This project allows you to control the angle of a servo motor by moving the joystick's X-axis.
// The servo motor moves to the position based on the joystick movement, where full left corresponds to 0° and full right to 180°.
//
// Components Used:
// - Arduino Nano (or any other Arduino)
// - Servo Motor
// - 5-pin Joystick Module
//
// For more projects and to buy components, visit: http://kitkraft.in

#include <Servo.h>   // Include the Servo library

// Create a servo object to control the servo motor
Servo myServo;

// Define pin connections for joystick and servo
const int VRxPin = A0;    // Pin connected to Joystick X-axis (VRx)
const int SWPin = 2;      // Pin connected to Joystick button (optional)
const int servoPin = 9;   // Pin connected to Servo Signal

// Variables for joystick position and servo angle
int xPosition = 0;    // Variable to store X-axis value from joystick
int angle = 0;        // Servo angle (0 to 180 degrees)

void setup() {
  Serial.begin(9600);          // Start serial communication for debugging
  myServo.attach(servoPin);    // Attach the servo to the servo pin
  pinMode(SWPin, INPUT_PULLUP); // Set the joystick button pin as input with pull-up resistor

  // Start with the servo at 90 degrees (middle position)
  myServo.write(90);         
  delay(1000);                 // Wait for servo to reach position
}

void loop() {
  // Read the joystick's X-axis value (from 0 to 1023)
  xPosition = analogRead(VRxPin);        

  // Map the joystick's X-axis value to the servo angle (0 to 180 degrees)
  angle = map(xPosition, 0, 1023, 0, 180);  

  // Move the servo to the calculated angle
  myServo.write(angle);      
  delay(15);                 // Small delay for smooth servo movement

  // Optional: Check if the joystick button is pressed
  if (digitalRead(SWPin) == LOW) {
    Serial.println("Button Pressed!");
    // Additional actions can be added when the button is pressed (optional)
  }

  // Print the joystick position and corresponding servo angle for debugging
  Serial.print("Joystick X: ");
  Serial.print(xPosition);
  Serial.print(" -> Servo Angle: ");
  Serial.println(angle);
}
