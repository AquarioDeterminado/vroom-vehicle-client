#ifndef LINESENSOR_H
#define LINESENSOR_H

#include "Arduino.h"

class LineSensor {
  public:
    LineSensor(int outPin);
    void setUp();
    bool isOnLine();
  private:
    int _outPin;
};

#endif