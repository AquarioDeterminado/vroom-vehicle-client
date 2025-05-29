#include "ComponentsController.h"

ComponentsController::ComponentsController() {}

void ComponentsController::setUp () {
  _uSSFront->setUp();

  _bCLeft->setUp();
  _bCRight->setUp();

  _lS->setUp();

  _aM->setUp();
}

BridgeController* ComponentsController::getLeftBridge() {
  return _bCLeft;
}

BridgeController* ComponentsController::getRightBridge() {
  return _bCRight;
}

UltraSonicSensor* ComponentsController::getUSS() {
  return _uSSFront;
}

LineSensor* ComponentsController::getLS() {
  return _lS;
}

Acelarometer* ComponentsController::getAM() {
  return _aM;
}