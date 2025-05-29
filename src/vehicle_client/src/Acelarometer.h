#ifndef ACELAROMETER_H
#define ACELAROMETER_H

#include "Arduino.h"
#include "My_MPU6050.h"
#include <Adafruit_Sensor.h>
#include <Wire.h>

class Acelarometer {
  public:
    Acelarometer();
    //General Constructor
    Acelarometer(int int1Pin, int int2Pin, int csPin, int sd0Pin, int sdaPin);
    void setUp();
    void getEvent (sensors_event_t* a,sensors_event_t* g,sensors_event_t* temp);
  private:
    Adafruit_MPU6050 _mpu;
    int _int1Pin;
    int _int2Pin;
    int _csPin;
    int _sd0Pin;
    int _sdaPin;
};

#endif