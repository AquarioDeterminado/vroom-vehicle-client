#include "UltraSonicSensor.h"

UltraSonicSensor::UltraSonicSensor(int triggerPin, int echoPin) {
  _triggerPin = triggerPin;
  _triggerPin = echoPin;
}

void UltraSonicSensor::setUp() {
  pinMode(_triggerPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

//Get distance in cm
float UltraSonicSensor::getDistance() {
  digitalWrite(_triggerPin, LOW);
  delay(2);
  
  digitalWrite(_triggerPin, HIGH);
  delay(10);
  digitalWrite(_triggerPin, LOW);
  
  float timing = pulseIn(_triggerPin, HIGH);
  float distance = timing * 0.034/2;
  
  return distance;
}

