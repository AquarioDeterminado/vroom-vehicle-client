#ifndef COMPONENTSCONTROLLER_H
#define COMPONENTSCONTROLLER_H

#include "UltraSonicSensor.h"
#include "BridgeController.h"
#include "LineSensor.h"
#include "Acelarometer.h"
#include "MovementController.h"
#include "SelfDriveController.h"
#include "constants.h"

//Motor Bridges 
BridgeController bCLeft(BRIDGELEFT_IN1, BRIDGELEFT_IN2, BRIDGELEFT_ENA, BRIDGELEFT_IN3, BRIDGELEFT_IN4, BRIDGELEFT_ENB);
BridgeController bCRight(BRIDGERIGHT_IN1, BRIDGERIGHT_IN2, BRIDGERIGHT_ENA, BRIDGERIGHT_IN3, BRIDGERIGHT_IN4, BRIDGERIGHT_ENB);

//Ultra Sonic Sensors
UltraSonicSensor uSSFront(ULTRASOFRONT_TRIG, ULTRASOFRONT_ECHO);
UltraSonicSensor uSSBack(ULTRASOBACK_TRIG, ULTRASOBACK_ECHO);

//Line Sensor
LineSensor lS(LINE_OUT);

//Acelarometer
Acelarometer aM;  

MovementController movementController(bCLeft, bCRight);

SelfDriveController selfDriveController;

void SetUpComponents () {
  uSSFront.setUp();
  uSSBack.setUp();

  bCLeft.setUp();
  bCRight.setUp();

  lS.setUp();
}

#endif
