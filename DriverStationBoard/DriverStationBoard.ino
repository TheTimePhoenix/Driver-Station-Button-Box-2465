#include <Joystick.h>

// Application for control of a FIRST Robotics Competition button box.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//
//(plus a couple tweaks by Phoenix Ma)
//--------------------------------------------------------------------

// Creates a joystick
Joystick_ Joystick;

void setup() {
  // Initializes button pins
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
  

  // Initializes Joystick library
  Joystick.begin();
}

// Constant that identifies the number of buttons
const int numberOfButtons = 12;

// Variable that stores the current button value
int currentButtonState;

// Array list that stores last state of the buttons
int lastButtonState[numberOfButtons] = {0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {
  // Reads pin values and sets button values accordingly
  for (int currentButton = 0; currentButton < numberOfButtons; currentButton++) {
    currentButtonState = !digitalRead(currentButton);
    if (lastButtonState[currentButton] != currentButtonState) {
      lastButtonState[currentButton] = currentButtonState;
      Joystick.setButton(currentButton, currentButtonState);
    }
  }
}