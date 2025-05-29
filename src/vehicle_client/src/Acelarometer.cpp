#include "Acelarometer.h"

Acelarometer::Acelarometer() {}

void Acelarometer::setUp() {
  int timeOut = 1 * 1000; //seconds

  bool isMpuActive = false;

  if (!isMpuActive) {
    isMpuActive = _mpu.begin();
    Serial.println("Failed to find MPU6050 chip");
    while (timeOut > 0 ) {
      delay(10);
      timeOut =- 10;
    }
  }
  _mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  _mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  _mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void Acelarometer::getEvent (sensors_event_t* a,sensors_event_t* g,sensors_event_t* temp) {
  _mpu.getEvent(a, g, temp);
}