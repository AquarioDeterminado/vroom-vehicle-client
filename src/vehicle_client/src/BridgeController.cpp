#include "BridgeController.h"

BridgeController::BridgeController () {
  
}

BridgeController::BridgeController(int wheel1FowardPin, int wheel1BackPin, int wheel1VelocityPin, int wheel2FowardPin, int wheel2BackPin, int wheel2VelocityPin) {
  _wheel1FowardPin = wheel1FowardPin;
  _wheel1BackPin = wheel1BackPin;
  _wheel1VelocityPin = wheel1VelocityPin;
  _wheel2FowardPin = wheel2FowardPin;
  _wheel2BackPin = wheel2BackPin;
  _wheel2VelocityPin = wheel2VelocityPin;
}

void BridgeController::setUp() {
  pinMode(_wheel1FowardPin, OUTPUT);
  pinMode(_wheel1BackPin, OUTPUT);
  pinMode(_wheel1VelocityPin, OUTPUT);
  analogWrite(_wheel1VelocityPin, 127);

  pinMode(_wheel2FowardPin, OUTPUT);
  pinMode(_wheel2BackPin, OUTPUT);
  pinMode(_wheel2VelocityPin, OUTPUT);
  analogWrite(_wheel2VelocityPin, 127);
}

void BridgeController::wheelGo(int wheelNumber, bool goFoward) {
  //Reset Wheel
  this->wheelStop(wheelNumber);

  Serial.println("moving wheel: ");
  Serial.print(wheelNumber);
  Serial.println("pin numbers: ");
  Serial.print(_wheel1FowardPin);
  Serial.print("; ");
  Serial.print(_wheel1BackPin);
  Serial.print("; ");
  Serial.print(_wheel2FowardPin);
  Serial.print("; ");
  Serial.print(_wheel2BackPin);
  Serial.print("; ");
  if (wheelNumber == 1) {
    if (goFoward)
      digitalWrite(_wheel1FowardPin, HIGH);
    else 
      digitalWrite(_wheel1BackPin, HIGH);
  } else if (wheelNumber == 2) {
    if (goFoward)
      digitalWrite(_wheel2FowardPin, HIGH);
    else 
      digitalWrite(_wheel2BackPin, HIGH);
  }
}

void BridgeController::wheelStop(int wheelNumber) {
  if(wheelNumber == 1) {
    digitalWrite(_wheel1FowardPin, LOW);
    digitalWrite(_wheel1BackPin, LOW);
  } else if (wheelNumber == 2) {
    digitalWrite(_wheel2FowardPin, LOW);
    digitalWrite(_wheel2BackPin, LOW);
  }
}

void BridgeController::setSpeed(int speed, int wheelNumber) {
  if(wheelNumber == 1) {
    analogWrite(_wheel1VelocityPin, speed);
  } else if (wheelNumber == 2) {
    analogWrite(_wheel2VelocityPin, speed);
  }
}


