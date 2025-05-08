#ifndef ACELAROMETER_H
#define ACELAROMETER_H

#include "Arduino.h"

class Acelarometer {
  public:
    //ESP32-1 constructor
    Acelarometer();
    //ESP32-2 constructor
    Acelarometer(int csPin, int sd0Pin, int sdaPin);
    //General Constructor
    Acelarometer(int int1Pin, int int2Pin, int csPin, int sd0Pin, int sdaPin);
    void setUp();
    void test();

  private:
    //Adafruit_ADXL345_Unified _sensor;
    int _int1Pin;
    int _int2Pin;
    int _csPin;
    int _sd0Pin;
    int _sdaPin;
};

#endif