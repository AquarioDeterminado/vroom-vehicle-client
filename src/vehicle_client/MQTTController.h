#ifndef MQTTCONTROLLER_H
#define MQTTCONTROLLER_H

#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include "constants.h"

class MqttController
{
  public:
    MqttController();
    void start();
    void sendMessage(char * topic, int value);
    void poll();
  private:
    
};

#endif