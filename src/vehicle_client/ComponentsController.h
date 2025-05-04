#ifndef COMPONENTSCONTROLLER_H
#define COMPONENTSCONTROLLER_H

#include "UltraSonicSensor.h"
#include "BridgeController.h"
#include "LineSensor.h"
#include "constants.h"

//Motor Bridges 
BridgeController BC1(BRIDGE1_IN1, BRIDGE1_IN2, BRIDGE1_ENA, BRIDGE1_IN3, BRIDGE1_IN4, BRIDGE1_ENB);
BridgeController BC2(BRIDGE2_IN1, BRIDGE2_IN2, BRIDGE2_ENA, BRIDGE2_IN3, BRIDGE2_IN4, BRIDGE2_ENB);

//Ultra Sonic Sensors
UltraSonicSensor uSS1(ULTRASO1_TRIG, ULTRASO1_ECHO);
UltraSonicSensor uSS2(ULTRASO2_TRIG, ULTRASO2_ECHO);

//Line Sensor
LineSensor LS(LINE_OUT);

//Acelarometer
//Acelarometer AM() TODO: Verificar qual é o ESP32

void SetUpComponents () {
  uSS1.setUp();
  uSS2.setUp();

  BC1.setUp();
  BC2.setUp();

  LS.setUp();
}

#endif
