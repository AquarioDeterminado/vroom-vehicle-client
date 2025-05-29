#ifndef COMPONENTSCONTROLLER_H
#define COMPONENTSCONTROLLER_H

#include "UltraSonicSensor.h"
#include "BridgeController.h"
#include "LineSensor.h"
#include "Acelarometer.h"
#include "constants.h"

class ComponentsController {
  public:
    ComponentsController();
    void setUp();
    BridgeController* getLeftBridge();
    BridgeController* getRightBridge();
    UltraSonicSensor* getUSS();
    LineSensor* getLS();
    Acelarometer* getAM();
  private:
    BridgeController* _bCLeft = new BridgeController(BRIDGELEFT_IN1, BRIDGELEFT_IN2, BRIDGELEFT_ENA, BRIDGELEFT_IN3, BRIDGELEFT_IN4, BRIDGELEFT_ENB);
    BridgeController* _bCRight = new BridgeController(BRIDGERIGHT_IN1, BRIDGERIGHT_IN2, BRIDGERIGHT_ENA, BRIDGERIGHT_IN3, BRIDGERIGHT_IN4, BRIDGERIGHT_ENB);

    //Ultra Sonic Sensors
    UltraSonicSensor* _uSSFront = new UltraSonicSensor(ULTRASOFRONT_TRIG, ULTRASOFRONT_ECHO);

    //Line Sensor
    LineSensor* _lS = new LineSensor(LINE_OUT);

    //Acelarometer
    Acelarometer* _aM = new Acelarometer();  
};

#endif
