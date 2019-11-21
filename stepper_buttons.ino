/*
  Stepper motor with buttons

  Turns a stepper motor clockwise and anticlockwise using an A4988 driver
  and 2 buttons.

  The circuit:
  --
  
  created 2019
  by Henry Dore <henrymonkey@gmail.com>
  This example code is in the public domain.
*/

const int button1Pin = 8;     // pushbutton 1 pin
const int button2Pin = 9;     // pushbutton 2 pin
const int stepPin = 7;        // A4988 step spin
const int dirPin = 6;         // A4988 dir pin

// variables
int button1State = 0;         // variables for reading the pushbutton status
int button2State = 0;
int pulseWidth = 2000;        //width of pulse sent to A4988 in microseconds
int pulseGap = 2000;          //time between pulses in microseconds

void setup() {
  // initialize the A4988 pins as outputs:
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  // initialize the pushbutton pins as an inputs:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

}

void loop() {
  // read the state of the pushbutton values:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // check if either pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1State == HIGH) {
    // turn motor clockwise:
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(pulseGap);

  } else if (button2State == HIGH) {
    // turn motor anti-clockwise:
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(pulseGap);
  } else {
    // Do nothing
  }
}
