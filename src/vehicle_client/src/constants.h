#ifndef CONSTANTS_H
#define CONSTANTS_H
/* Constants file */ 
/* --- ESP32 PINS --- */
//UltraSonic Sensor Pins
#define ULTRASOFRONT_TRIG 27
#define ULTRASOFRONT_ECHO 14

//Motor Bridge Pins
#define BRIDGELEFT_ENA 23
#define BRIDGELEFT_IN1 22
#define BRIDGELEFT_IN2 21
#define BRIDGELEFT_IN3 19
#define BRIDGELEFT_IN4 18
#define BRIDGELEFT_ENB 5

#define BRIDGERIGHT_ENA 32
#define BRIDGERIGHT_IN1 15
#define BRIDGERIGHT_IN2 2
#define BRIDGERIGHT_IN3 4
#define BRIDGERIGHT_IN4 16
#define BRIDGERIGHT_ENB 17

//Line Sensor 
#define LINE_OUT 26

//Acelarometer Sensor 
#define ACELAROMETER_INT1 25
#define ACELAROMETER_INT2 33
/* --- END ESP32-1 PINS --- */

//WIFI Config
#define WIFI_SSID F("hi-five")
#define WIFI_PASS F("zyskiw-zinxa8-dyjbUp")

//MQTT Config
#define MQTT_SERVER_HOST F("192.168.10.79")
#define MQTT_SERVER_PORT 1883

//MQTT Topics 
#define MQTT_TOPIC_BATTERY F("vehicle/batteryPercentage")
#define MQTT_TOPIC_SPEED F("vehicle/speed")
#define MQTT_TOPIC_INCLINATION F("vehicle/inclination")
#define MQTT_TOPIC_TRIPS F("vehicle/trips")
#define MQTT_TOPIC_MOVEMENT F("vehicle/moves")
#define MQTT_TOPIC_ACTION F("vehicle/actions")
#define MQTT_TOPIC_PING F("vehicle/ping")

#endif
