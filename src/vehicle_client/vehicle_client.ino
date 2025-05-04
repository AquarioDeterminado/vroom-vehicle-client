#include "Arduino.h"
#include <ArduinoMqttClient.h>
#include <WiFi.h>
#include "MQTTController.h"
#include "ComponentsController.h" 
#include "constants.h"

MqttController mqttController;

void setup() {
  //Set Up Components
  SetUpComponents();

  //Begin Serial Connection
  Serial.begin(9600);

  //mqttController.start();
}


void loop() 
{
  //check broker
  mqttController.poll();

  /* --- Ulta Sonic Sendor Test --- */
  Serial.print("test: ");
  Serial.println();
  BC1.wheelGo(1, true);
  /* --- End Test --- */
}

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
