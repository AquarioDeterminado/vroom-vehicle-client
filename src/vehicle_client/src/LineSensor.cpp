#include "LineSensor.h"

LineSensor::LineSensor (int outPin) {
  _outPin = outPin;
}

void LineSensor::setUp() {
  pinMode(_outPin, INPUT);
}

bool LineSensor::isOnLine() {
  int isOnLine = digitalRead(_outPin);

  if (isOnLine == 0)
    return false;
  else if (isOnLine == 1)
    return true;
}