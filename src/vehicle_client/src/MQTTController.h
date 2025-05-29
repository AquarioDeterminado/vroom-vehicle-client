#ifndef MQTTCONTROLLER_H
#define MQTTCONTROLLER_H

#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include <stdlib.h>
#include "constants.h"

class MqttController
{
  public:
    MqttController();
    void start();
    void sendMessage(char * topic, int value);
    void sendMessage(char * topic, String value);
    void poll();
    String messageTopic();
    char* getIncomingMessage(int messageSize);
    void setCallBack(void (*callBack)(int));
  private:
};

#endif