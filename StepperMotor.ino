#include <Stepper.h>

#define BTN_PIN 7
#define REV_BTN_PIN 4

const int STEPS_PER_REV = 2048;
const int SPEED = 12;

// This is how many rotations are needed to achieve 3ft
const float TURNS = 5.82123758454;

Stepper stppr = Stepper(STEPS_PER_REV, 8, 10, 9, 11);

bool btnPressed;
bool revBtnPressed;

void setup() {
  // Max speed 15
  stppr.setSpeed(SPEED);
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(REV_BTN_PIN, INPUT_PULLUP);
  btnPressed = true;
  revBtnPressed == true;
}

void loop() {
  btnPressed = digitalRead(BTN_PIN);
  revBtnPressed = digitalRead(REV_BTN_PIN);
  if (btnPressed == false) {
    stppr.step(STEPS_PER_REV * TURNS);
    btnPressed = true;
  }
  if (revBtnPressed == false) {
    stppr.step(-(STEPS_PER_REV * TURNS));
    revBtnPressed = true;
  }
}
