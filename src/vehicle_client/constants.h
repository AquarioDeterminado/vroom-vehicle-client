#ifndef CONSTANTS_H
#define CONSTANTS_H

/* Constants file */ 

//ESP32 PINS
const int TEST_PIN25 = 2;
const int TEST_PIN26 = 4;



const int BRIDGE1_IN1 = 27;
const int BRIDGE1_IN2 = 14;
const int BRIDGE1_IN3 = 12;
const int BRIDGE1_IN4 = 13;


//WIFI Config
#define WIFI_SSID F("wantmorecoffee")
#define WIFI_PASS F("yesplease")

//MQTT Config
#define MQTT_SERVER_HOST F("169.254.82.75")
const int MQTT_SERVER_PORT = 1883;

//MQTT Topics 
#define MQTT_TOPIC_BATTERY F("vehicle/batteryPercentage")
#define MQTT_TOPIC_SPEED F("vehicle/speed")
#define MQTT_TOPIC_INCLINATION F("vehicle/inclination")
#define MQTT_TOPIC_TRIPS F("vehicle/trips")
#define MQTT_TOPIC_MOVEMENT F("vehicle/moves")
#define MQTT_TOPIC_PRESETACTION F("vehicle/actions")

#endif
