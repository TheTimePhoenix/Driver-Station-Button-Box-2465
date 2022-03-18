#include <Joystick.h>

// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// The digital pins 9, 10, 11, and 12 are grounded when they are pressed.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//
//(plus a couple tweaks by Phoenix Ma)
//--------------------------------------------------------------------

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 0;
const int numButton = 14;

// Last state of the button
int lastButtonState[numButton] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {
boolean sent = false;
  // Read pin values
  for (int index = 0; index < numButton; index++) {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index]) {
      lastButtonState[index] = currentButtonState;
      Joystick.setButton(index, currentButtonState);
    }
  }
  delay(50);
}