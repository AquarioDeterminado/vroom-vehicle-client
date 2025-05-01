#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include "MQTTController.h"
#include "constants.h"

MqttController mqttController;

void setup() {
  //Set Up ESP32 Pins
  SetUpPins();

  //Begin Serial Connection
  Serial.begin(9600);

  mqttController.start();
}

void SetUpPins () {
  //Bridge 1 pins 

  pinMode(BRIDGE1_IN1, OUTPUT);
  pinMode(BRIDGE1_IN2, OUTPUT);
  pinMode(BRIDGE1_IN3, OUTPUT);
  pinMode(BRIDGE1_IN4, OUTPUT);


  //Test SetUp
  pinMode(TEST_PIN25, OUTPUT);
  pinMode(TEST_PIN26, INPUT);

  digitalWrite(TEST_PIN26, LOW);

  return;
}

void loop() 
{
  //check broker
  mqttController.poll();


  /* --- Test --- */
  // Rotate the Motor A clockwise
  digitalWrite(BRIDGE1_IN1, HIGH);
  digitalWrite(BRIDGE1_IN2, LOW);
  digitalWrite(BRIDGE1_IN3, HIGH);
  digitalWrite(BRIDGE1_IN4, LOW);
  delay(2000);
  // Motor A
  digitalWrite(BRIDGE1_IN1, HIGH);
  digitalWrite(BRIDGE1_IN2, HIGH);
  digitalWrite(BRIDGE1_IN3, HIGH);
  digitalWrite(BRIDGE1_IN4, HIGH);
  delay(500);
  /* --- End Test --- */
}

/*
void loop()
{
  digitalWrite(TEST_PIN26, LOW);
  delay(2);
  
  digitalWrite(TEST_PIN26, HIGH);
  delay(10);
  digitalWrite(TEST_PIN26, LOW);
  
  float timing = pulseIn(TEST_PIN25, HIGH);
  float distance = (timing * 0.034) / 2;
  
  Serial.print("Distance: ");
  Serial.print(timing);
  Serial.print("cm | ");
  Serial.print(distance / 2.54);
  Serial.println("in");
  
  delay(100);
}
*/

/*
void loop() {
  // Rotate the Motor A clockwise
  digitalWrite(BRIDGE1_IN1, HIGH);
  digitalWrite(BRIDGE1_IN2, LOW);
  digitalWrite(BRIDGE1_IN3, HIGH);
  digitalWrite(BRIDGE1_IN4, LOW);
  delay(2000);
  // Motor A
  digitalWrite(BRIDGE1_IN1, HIGH);
  digitalWrite(BRIDGE1_IN2, HIGH);
  digitalWrite(BRIDGE1_IN3, HIGH);
  digitalWrite(BRIDGE1_IN4, HIGH);
  delay(500);
}
*/

/*
#include <tcs3200.h>


#define S0PIN 32
#define S1PIN 33
#define S2PIN 25
#define S3PIN 26
#define OUTPIN 27
#define LEDPIN 12
#define OPIN 14



tcs3200 tcs(S0PIN, S1PIN, S2PIN, S3PIN, OUTPIN);
int red, green, blue, white;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Set UP Wifi connection
}

void loop() {
  red = tcs.colorRead('r');   //reads color value for red
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("    ");
  
  green = tcs.colorRead('g');   //reads color value for green
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("    ");

  blue = tcs.colorRead('b');    //reads color value for blue
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("    ");

  white = tcs.colorRead('c');    //reads color value for white(clear)
  Serial.print("W(clear)= ");
  Serial.print(white);
  Serial.print("    ");

  Serial.println();

  delay(200);
}
*/
