#pragma once

#include <Adafruit_NeoPixel.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
using led_strip = Adafruit_NeoPixel;
using mpu_sensor = mpu_sensor;

int initialize_mpu(mpu_sensor& mpu);
int initialize_leds(led_strip& pixels);
int initialize_serial(HardwareSerial& serial);