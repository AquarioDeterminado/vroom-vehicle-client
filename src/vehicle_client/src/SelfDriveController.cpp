#include "SelfDriveController.h"

SelfDriveController::SelfDriveController(ComponentsController* componentsController, MqttController* client, MovementController* movementController) {
  _componentsController = componentsController;
  _client = client;
  _movementController = movementController;
}

void SelfDriveController::begin() {
  _client->sendMessage((char*)MQTT_TOPIC_TRIPS, "{\"action\": \"start\"}");
  _movementController->changeSpeed(127);
  this->onTrip = true;
}

void SelfDriveController::setCurrentTripId(char* currentTripID) {
  Serial.println(currentTripID);
  _currentTripID = currentTripID;
}

void SelfDriveController::loop() {
  //Checks Rotations change
  rotateUpdater();

  //Make Checks
  checkIfError(ErrorType::DISTANCE);
  checkIfError(ErrorType::LINE);
  checkIfError(ErrorType::RAMP);
  checkIfError(ErrorType::ROTATION);

  handleErrors();
  
  if(!isHandelingError())
    _movementController->move(Direction::FOWARD);
}


void SelfDriveController::handleErrors() {
  if (handelingError[ErrorType::DISTANCE])
    correctDistance();
  if (handelingError[ErrorType::LINE])
    correctLine();
  if (handelingError[ErrorType::RAMP])
    correctRamp();
  if (handelingError[ErrorType::ROTATION])
    correctRotation();
}

void SelfDriveController::checkIfError(ErrorType error) {
  bool checker = getErrorChecker(error);

  if(!checker) {
    if(!alreadyCorretingError(error)) 
      correctionCounters[error] = millis();
    handelingError[error] = true;
  }
} 

bool SelfDriveController::getErrorChecker(ErrorType error) {
  switch (error) {
    case ErrorType::DISTANCE:
      return this->hasDistance();
      break;
    case ErrorType::LINE:
      return this->isOnLine();
      break;
    case ErrorType::RAMP:
      return this->isOnRamp();
      break;
    case ErrorType::ROTATION:
      return this->isFacingFoward();
      break;
  }

}

//HANDLE ERROR
bool SelfDriveController::isHandelingError() {
  int i = 0;
  while (i < ErrorType::SIZE) {
    if (handelingError[i])
      return true;
    i ++;
  }
  return false;
}

bool SelfDriveController::alreadyCorretingError(ErrorType errorType) {
  return handelingError[errorType];
}

/* --- Check Distance --- */
void SelfDriveController::correctDistance () {
  float currentTime = millis();
  float delta = currentTime - correctionCounters[ErrorType::DISTANCE];

  if(delta <= timeForCrabWalk) {
    _movementController->stop();
    crabWalk();
  } else {
    handelingError[ErrorType::DISTANCE] = false;
  }
}

void SelfDriveController::crabWalk() { //TODO: CHANGE
  if(currentCrabWalk)
    _movementController->move(Direction::RIGHT);
  else
    _movementController->move(Direction::LEFT);
}

bool SelfDriveController::hasDistance(){
  float distance = _componentsController->getUSS()->getDistance();
  if(distance >= maximumDistance)
    return true;
  else 
    return false;
}
/* --- End Check --- */


/* --- Check Line --- */
void SelfDriveController::correctLine() {

  if(!hasInversed){
    inverse();
    hasInversed = true;
  }

  float currentTime = millis();
  float delta = currentTime - correctionCounters[ErrorType::DISTANCE];
  Serial.println("delta: ");
  Serial.print(delta);
  if(delta <= timeForCrabWalk) {
    crabWalk(); //TODO CHANGE
  } else {
    hasInversed = false;
    handelingError[ErrorType::LINE] = false;
  }
}

void SelfDriveController::inverse() {
  _movementController->stop();
  currentCrabWalk = !currentCrabWalk;
  crabWalk(); //TODO CHANGE
}

bool SelfDriveController::isOnLine() {
  int isOnLine = digitalRead(26); //TODO CHANGE
  Serial.println(isOnLine);
  return isOnLine;
}
/* --- End Check --- */


/* --- Check Ramp --- */


bool SelfDriveController::isOnRamp() {
  return currentPitchAngle <= 10.00 || currentPitchAngle >= - 10.00;
}

void SelfDriveController::correctRamp() {
  if (isOnRamp())
    speedUp();
  else
    handelingError[ErrorType::RAMP] = false;
}

void SelfDriveController::speedUp() {
  _movementController->changeSpeed(255); //TODO CHANGE
}
/* --- End Check --- */


/* --- Check Rotation --- */
void SelfDriveController::correctRotation() {
  if (isFacingFoward())
    handelingError[ErrorType::ROTATION] = false;
  else 
    _movementController->rotate(currentYawAngle);
}

bool SelfDriveController::isFacingFoward() {
  return currentYawAngle <= 10.00 || currentYawAngle >= -10.00;
}


void SelfDriveController::end() {
  this->onTrip = false;
  String message = "{\"action\": \"end\",\"id\": \"";

  Serial.println("ending: ");
  Serial.print (_currentTripID);
  message.concat(_currentTripID);
  message.concat("\" }");

  _client->sendMessage((char*)MQTT_TOPIC_TRIPS, message);
}

/* --- REMOVE --- */

void SelfDriveController::rotateUpdater() {
  sensors_event_t a, g, temp;
  _componentsController->getAM()->getEvent(&a, &g, &temp);

  float oldTime = this->currentTime;
  this->currentTime = millis();
  float delta = currentTime - oldTime;
  float movedYawAngle = (g.gyro.z * (180 / 3.1415)) * (delta / 1000);

  float pitchVelo = 0;
  if (pitchAxis == 'x')
    pitchVelo = g.gyro.x;
  else 
    pitchVelo = g.gyro.y;

  float movedPitchAngle = (pitchVelo * (180 / 3.1415)) * (delta / 1000);

  if (movedYawAngle >= 1 || movedYawAngle <= -1)
    this->currentYawAngle += movedYawAngle;

  if (movedPitchAngle >= 1 || movedPitchAngle <= -1)
    this->currentPitchAngle += movedPitchAngle;

  Serial.print("Current Yaw Angle: ");
  Serial.print(this->currentYawAngle);
  Serial.println("º;");
  Serial.print("Current Pitch Angle: ");
  Serial.print(this->currentYawAngle);
  Serial.println("º;");
  delay(200);
}

