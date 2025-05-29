#ifndef SELFDRIVECONTROLLER_H
#define SELFDRIVECONTROLLER_H

#include "MQTTController.h"
#include "ComponentsController.h"
#include "MovementController.h"
#include <Adafruit_Sensor.h>
#include <Wire.h>

enum ErrorType {
  DISTANCE = 0,
  LINE = 1,
  RAMP = 2,
  ROTATION = 3,
  SIZE = 4
};

class SelfDriveController {
  public:
    SelfDriveController(ComponentsController* componentsController, MqttController* client, MovementController* movementController);
    void begin();
    void setCurrentTripId(char* currentTripID);
    void loop();
    void end();
    bool onTrip;
  private:
    char* _currentTripID;
    ComponentsController* _componentsController;
    MqttController* _client;
    MovementController* _movementController;

    char pitchAxis = 'x';

    float currentYawAngle = 0.0;
    float currentPitchAngle = 0.0;
    float maxAngle = 10.00;
    float currentTime = millis();

    const int maximumDistance = 15; //cm
    const float timeForCrabWalk = 3 * 1000; //3 seconds;
    const int rotationThreshold = 25; //º


    int lastDirection = 0; //0 - foward; 1 - Back; 2 - Left; 3 - Rigth;
    bool currentCrabWalk = true; //true - right; false - Left;
    bool handelingError[ErrorType::SIZE] = {false, false, false, false};
    float correctionCounters[ErrorType::SIZE];
    bool hasInversed = false;

    void checkIfError(ErrorType error);
    bool getErrorChecker(ErrorType error);
    void handleErrors();
    bool isHandelingError();
    bool alreadyCorretingError(ErrorType errorType);

    float readDistance();
    bool hasDistance();
    void correctDistance(); //TEST
    void crabWalk();

    void correctLine();
    void inverse();
    bool isOnLine();

    void rotateUpdater();

    bool isOnRamp(); 
    void correctRamp(); 
    void speedUp(); 

    void correctRotation(); 
    bool isFacingFoward(); 

};

#endif