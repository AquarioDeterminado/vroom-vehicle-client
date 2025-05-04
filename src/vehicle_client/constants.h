/* Constants file */ 
#ifndef ESP32_NUM
//Current ESP32 Number (either 1 or 2)
#define ESP32_NUM 1
#endif

#if ESP32_NUM == 1
/* --- ESP32-1 PINS --- */
#define TEST_PIN25 0
#define TEST_PIN26 0

//UltraSonic Sensor Pins
#define ULTRASO1_TRIG 27
#define ULTRASO1_ECHO 14

#define ULTRASO2_TRIG 12
#define ULTRASO2_ECHO 13

//Motor Bridge Pins
#define BRIDGE1_ENA 23
#define BRIDGE1_IN1 22
#define BRIDGE1_IN2 21
#define BRIDGE1_IN3 19
#define BRIDGE1_IN4 18
#define BRIDGE1_ENB 5

#define BRIDGE2_ENA 15
#define BRIDGE2_IN1 2
#define BRIDGE2_IN2 0
#define BRIDGE2_IN3 4
#define BRIDGE2_IN4 16
#define BRIDGE2_ENB 17

//Line Sensor 
#define LINE_OUT 26

//Acelarometer Sensor 
#define ACELAROMETER_INT1 25
#define ACELAROMETER_INT2 33
/* --- END ESP32-1 PINS --- */

#elif ESP32_NUM == 2
/* --- ESP32-2 PINS --- */
//Acelarometer Sensor 
#define ACELAROMETER_CS 23
#define ACELAROMETER_SD0 22
#define ACELAROMETER_SDA 21
/* --- END ESP32-2 PINS --- */
#endif

#ifndef CONSTANTS_H
#define CONSTANTS_H
//WIFI Config
#define WIFI_SSID F("wantmorecoffee")
#define WIFI_PASS F("yesplease")

//MQTT Config
#define MQTT_SERVER_HOST F("169.254.82.75")
#define MQTT_SERVER_PORT 1883

//MQTT Topics 
#define MQTT_TOPIC_BATTERY F("vehicle/batteryPercentage")
#define MQTT_TOPIC_SPEED F("vehicle/speed")
#define MQTT_TOPIC_INCLINATION F("vehicle/inclination")
#define MQTT_TOPIC_TRIPS F("vehicle/trips")
#define MQTT_TOPIC_MOVEMENT F("vehicle/moves")
#define MQTT_TOPIC_PRESETACTION F("vehicle/actions")

#endif
