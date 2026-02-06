#pragma once

#include <Adafruit_NeoPixel.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <led.h>

#define DELAY 10 //the delay beetween measures of the sensor, in ms

using led_strip = Adafruit_NeoPixel;
using mpu_sensor = Adafruit_MPU6050;

int initialize_mpu(mpu_sensor& mpu);
int initialize_leds(led_strip& pixels);
int initialize_serial(HardwareSerial& serial);

int position_to_led(float position);