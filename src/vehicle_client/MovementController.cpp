#include "MovementController.h"

MovementController::MovementController(BridgeController bridgeLeft, BridgeController bridgeRight) {
  _bridgeLeft = bridgeLeft;
  _bridgeRight = bridgeRight;
}

void MovementController::move(Direction direction, float speed) {
  Serial.println("going vroom vroom");
  if (speed != _currentSpeed) 
    changeSpeed(speed);

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
      goVertical(true);
      break;
    case Direction::FOWARD_LEFT:
      goVertical(false);
      break;
    case Direction::BACK_RIGHT:
      goHorizontal(true);
      break;
    case Direction::BACK_LEFT:
      goHorizontal(false);
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

  _bridgeLeft.wheelStop(1);
  _bridgeLeft.wheelStop(0);
  _bridgeRight.wheelStop(1);
  _bridgeRight.wheelStop(0);
}

void MovementController::changeSpeed(float speed) {
  Serial.println("Changing Speed;");
  if (speed < 0 || speed > 255)
    return;

  _currentSpeed = speed;
  _bridgeLeft.setSpeed(_currentSpeed, 0);
  _bridgeLeft.setSpeed(_currentSpeed, 1);
  _bridgeRight.setSpeed(_currentSpeed, 0);
  _bridgeRight.setSpeed(_currentSpeed, 1);
}

void MovementController::goVertical(bool goFoward) {
  _bridgeLeft.wheelGo(1, goFoward);
  _bridgeLeft.wheelGo(0, goFoward);
  _bridgeRight.wheelGo(1, goFoward);
  _bridgeRight.wheelGo(0, goFoward);
}

void MovementController::goHorizontal (bool goRight) {
  _bridgeLeft.wheelGo(1, !goRight);
  _bridgeLeft.wheelGo(0, goRight);
  _bridgeRight.wheelGo(1, goRight);
  _bridgeRight.wheelGo(0, !goRight);
}


