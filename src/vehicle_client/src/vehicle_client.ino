#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include "MQTTController.h"
#include "ComponentsController.h" 
#include "MovementController.h"
#include "SelfDriveController.h"
#include "constants.h"

MqttController mqttController;

ComponentsController componentsController;

MovementController movementController(&componentsController);

SelfDriveController selfDriveController(&componentsController, &mqttController, &movementController);


void setup() {
  //Begin Serial Connection
  Serial.begin(9600);

  mqttController.setCallBack(onMqttMessage);
  mqttController.start();

  Serial.println("Setting up Components;");
  componentsController.setUp();
}

void loop() 
{
  //check broker
  mqttController.poll();
  
  if (selfDriveController.onTrip)
    selfDriveController.loop();
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
  else if (topic == MQTT_TOPIC_TRIPS) {
    char* token = strtok(message, " ");

    if(strcmp(token, "id") == 0) {
      char* id = strtok(NULL, " ");
      Serial.println("id: ");
      Serial.print(id);
      selfDriveController.setCurrentTripId(id);

      //free(id);
      //id = NULL;
    }
    //free(token);
    //Serial.println("freeing token;");
    //token = NULL;
  }
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
      if (!selfDriveController.onTrip)
        selfDriveController.begin();
      else 
        selfDriveController.end();
  } 
  else if (topic == MQTT_TOPIC_PING) {
    if(strcmp(message, "ping") == 0) {
      char* topic = (char*) MQTT_TOPIC_PING;
      mqttController.sendMessage(topic, "active;");
    } 
  }
  /*
  if( message != NULL ) {
    free(message);
    message = NULL;
  }
    */
}