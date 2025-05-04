#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "Arduino.h"
#include "constants.h"

class UltraSonicSensor 
{
  public:
    UltraSonicSensor(int triggerPin, int echoPin);
    void setUp();
    //Returns Distance in cm
    float getDistance();
  private:
    int _triggerPin;
    int _echoPin;
};

#endif