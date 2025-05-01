#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include <MQTTController.h>

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void StartMQQTConnection();
void StartWifiConnection();
void ConnectMQQTBroker();
void SubscribeTopics();

MqttController::MqttController() {
}

void MqttController::start() {
  StartWifiConnection();
  ConnectMQQTBroker();
  SubscribeTopics();
}

void MqttController::sendMessage(char * topic, int value) {
  mqttClient.beginMessage(topic);
  mqttClient.print(value);
  mqttClient.endMessage();
}

void MqttController::poll () {
  mqttClient.poll();
}

void StartWifiConnection() {
  Serial.println("Connecting to ");
  Serial.print(WIFI_SSID);

  while (WiFi.begin(WIFI_SSID, WIFI_PASS) != WL_CONNECTED) {
    Serial.println("Retrying Connection.");
    delay(5000);
  }
  
  Serial.println("Connected to Network.");
  Serial.println("");
}

void ConnectMQQTBroker() {
  char buffer[17];
  strncpy_P(buffer, (const char*)MQTT_SERVER_HOST, 16);
  if (!mqttClient.connect(buffer, MQTT_SERVER_PORT)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while(1);
  }
  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}


void SubscribeTopics() {
  mqttClient.subscribe(MQTT_TOPIC_BATTERY);
  mqttClient.subscribe(MQTT_TOPIC_SPEED);
  mqttClient.subscribe(MQTT_TOPIC_INCLINATION);
  mqttClient.subscribe(MQTT_TOPIC_TRIPS);
  mqttClient.subscribe(MQTT_TOPIC_MOVEMENT);
  mqttClient.subscribe(MQTT_TOPIC_PRESETACTION);
}

void onMqttMessage(int messageSize) 
{
  String topic = mqttClient.messageTopic();

  while (mqttClient.available()) {
    Serial.print((char)mqttClient.read());
  }
  Serial.println();

  if (topic == MQTT_TOPIC_BATTERY) {}
  else if (topic == MQTT_TOPIC_SPEED) {}
  else if (topic == MQTT_TOPIC_INCLINATION) {}
  else if (topic == MQTT_TOPIC_TRIPS) {}
  else if (topic == MQTT_TOPIC_MOVEMENT) {}
  else if (topic == MQTT_TOPIC_PRESETACTION) {}
}


