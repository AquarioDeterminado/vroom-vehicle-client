#ifndef MOVEMENTCONTROLLER_H
#define MOVEMENTCONTROLLER_H

#include "BridgeController.h"

typedef enum {
  FOWARD,
  BACK,
  LEFT,
  RIGHT,

  FOWARD_RIGTH,
  FOWARD_LEFT,
  BACK_RIGHT,
  BACK_LEFT
} Direction;

typedef enum {
  SPIN,
  SQUARE
  //TODO: ADD MORE PRESETS;
} MovePreset;

class MovementController {
  public:
    MovementController(BridgeController bridgeLeft, BridgeController bridgeRight);
    void move(Direction direction, float speed);
    //Doesnt change speed
    void move(Direction direction);
    //Move according to preset
    void move(MovePreset preset);
    void changeSpeed(float speed);
    void stop();
  private:
    BridgeController _bridgeLeft;
    BridgeController _bridgeRight;
    float _currentSpeed;
    Direction _lastDirection;
    void goVertical(bool goFoward);
    void goHorizontal (bool goRigth);
};

#endif