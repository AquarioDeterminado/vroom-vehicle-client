#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include "MQTTController.h"
#include "ComponentsController.h" 
#include "MovementController.h"
#include "SelfDriveController.h"
#include "constants.h"

MqttController mqttController;

//Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  //Set Up Components
  SetUpComponents();

  //Begin Serial Connection
  Serial.begin(9600);

  mqttController.start();
  mqttController.setCallBack(onMqttMessage);
}

void loop() 
{
  //check broker
  mqttController.poll();
}

void onMqttMessage(int messageSize) 
{
  Serial.println("Message Received");

  String topic = mqttController.messageTopic();
  char* message = mqttController.getIncomingMessage(messageSize);
  Serial.println("Message: ");
  Serial.println(message);

  if (topic == MQTT_TOPIC_BATTERY) {}
  else if (topic == MQTT_TOPIC_SPEED) {
    std::string buffer(message);
    float speed = std::stof(buffer);
    movementController.changeSpeed(speed);
  }
  else if (topic == MQTT_TOPIC_INCLINATION) {}
  else if (topic == MQTT_TOPIC_TRIPS) {}
  else if (topic == MQTT_TOPIC_MOVEMENT) {
    if(strcmp(message, "up") == 0)
      movementController.move(Direction::FOWARD);
    else if (strcmp(message, "down") == 0)
      movementController.move(Direction::BACK);
    else if (strcmp(message, "left") == 0)
      movementController.move(Direction::LEFT);
    else if (strcmp(message, "rgt") == 0)
      movementController.move(Direction::RIGHT);
    else if (strcmp(message, "dlf") == 0)
      movementController.move(Direction::FOWARD_RIGTH);
    else if (strcmp(message, "drf") == 0)
      movementController.move(Direction::FOWARD_LEFT);
    else if (strcmp(message, "dlb") == 0)
      movementController.move(Direction::BACK_RIGHT);
    else if (strcmp(message, "drb") == 0)
      movementController.move(Direction::BACK_LEFT);
    else if (strcmp(message, "stop") == 0)
      movementController.stop();
  }
  else if (topic == MQTT_TOPIC_ACTION) {
    if(strcmp(message, "sd") == 0)
      selfDriveController.begin();
  }
  free(message);
  message = NULL;
}