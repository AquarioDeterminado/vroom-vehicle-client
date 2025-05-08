#include "Acelarometer.h"


Acelarometer::Acelarometer() {
  //_sensor = Adafruit_ADXL345_Unified(12345);
}

void Acelarometer::test()  {
  /*Read from ADXL345 accelerometer
  sensors_event_t event; 
  _sensor.getEvent(&event);
 
  // Display the results (acceleration is measured in m/s^2) 
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  //Take a one second break*/
  delay(1000);
}