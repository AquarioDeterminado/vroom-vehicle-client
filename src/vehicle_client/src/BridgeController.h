#ifndef BRIDGECONTROLLER_H
#define BRIDGECONTROLLER_H

#include "Arduino.h"

class BridgeController {
  public:
    BridgeController();
    BridgeController(int wheel1FowardPin, int wheel1BackPin, int wheel1VelocityPin, int wheel2FowardPin, int wheel2BackPin, int wheel2VelocityPin);
    void setUp();
    void wheelGo(int wheelNumber, bool goFoward);
    void wheelStop(int wheelNumber);
    void setSpeed(int speed, int wheelNumber);
  private:
    int _wheel1FowardPin;
    int _wheel1BackPin;
    int _wheel1VelocityPin;
    int _wheel2FowardPin;
    int _wheel2BackPin;
    int _wheel2VelocityPin;
};

#endif