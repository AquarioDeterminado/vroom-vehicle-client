#include "MovementController.h"

MovementController::MovementController(ComponentsController* componentsController) {
  _bridgeLeft = componentsController->getLeftBridge();
  _bridgeRight = componentsController->getRightBridge();
}

void MovementController::move(Direction direction, float speed) {
  stop();
  
  if (speed != _currentSpeed) 
    changeSpeed(speed);

  _lastDirection = direction;

  switch(direction) {
    case Direction::FOWARD:
      goVertical(true);
      break;
    case Direction::BACK:
      goVertical(false);
      break;
    case Direction::RIGHT:
      goHorizontal(true);
      break;
    case Direction::LEFT:
      goHorizontal(false);
      break;
    case Direction::FOWARD_RIGTH:
      goDiagonal(true ,true);
      break;
    case Direction::FOWARD_LEFT:
      goDiagonal(false ,true);
      break;
    case Direction::BACK_RIGHT:
      goDiagonal(true ,false);
      break;
    case Direction::BACK_LEFT:
      goDiagonal(false ,false);
      break;
  }
}

void MovementController::move(Direction direction) {
  move(direction, _currentSpeed);
}

void MovementController::move(MovePreset preset) {
  //TODO
}

void MovementController::stop() {
  Serial.println("Stopping;");

  _bridgeLeft->wheelStop(1);
  _bridgeLeft->wheelStop(2);
  _bridgeRight->wheelStop(1);
  _bridgeRight->wheelStop(2);
}

void MovementController::changeSpeed(float speed) {
  Serial.println("Changing Speed;");
  if (speed < 0 || speed > 255)
    return;

  _currentSpeed = speed;
  _bridgeLeft->setSpeed(_currentSpeed, 1);
  _bridgeLeft->setSpeed(_currentSpeed, 2);
  _bridgeRight->setSpeed(_currentSpeed, 1);
  _bridgeRight->setSpeed(_currentSpeed, 2);
}

void MovementController::goVertical(bool goFoward) {
  _bridgeLeft->wheelGo(1, goFoward);
  _bridgeLeft->wheelGo(2, goFoward);
  _bridgeRight->wheelGo(1, goFoward);
  _bridgeRight->wheelGo(2, goFoward);
}

void MovementController::goHorizontal (bool goRight) {
  _bridgeLeft->wheelGo(1, !goRight);
  _bridgeLeft->wheelGo(2, goRight);
  _bridgeRight->wheelGo(1, goRight);
  _bridgeRight->wheelGo(2, !goRight);
}

void MovementController::goDiagonal (bool right, bool foward) {
  BridgeController* frontBridge;
  BridgeController* backBridge;

  if (right) {
    frontBridge = _bridgeRight;
    backBridge = _bridgeLeft;
  } else {
    frontBridge = _bridgeLeft;
    backBridge =  _bridgeRight;
  }
  frontBridge->wheelGo(2, foward);
  backBridge->wheelGo(1, foward);
}

void MovementController::rotate(float currentYawAngle) { //TODO CHANGE
  bool clockWise = currentYawAngle >= -10.00;

  _bridgeRight->wheelGo(1, clockWise);
  _bridgeRight->wheelGo(2, clockWise);

  _bridgeLeft->wheelGo(1, !clockWise);
  _bridgeLeft->wheelGo(2, !clockWise);
}

