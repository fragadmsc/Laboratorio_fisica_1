#pragma once

#include <Adafruit_NeoPixel.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

const int DELAY = 500; //the delay beetween measures of the sensor, in ms
const int LED_PIN = 13; //the pin of the led in the arduino
const int NUM_LEDS = 60; // the number of leds

const float COEF_OF_RESTITUTION = 0.5F; //the coefficient of restitution of the ball and the bottom, adimentional
const float TIME = 1.0F*DELAY/1000.0F; //the time beetween measurements from the sensor, in seconds
const float BAR_SIZE = 1.0F; //size of the bar, in meters


using led_strip = Adafruit_NeoPixel;
using mpu_sensor = Adafruit_MPU6050;

bool initialize_mpu(mpu_sensor& mpu);
bool initialize_leds(led_strip& pixels);
bool initialize_serial(HardwareSerial& serial);

int position_to_led(float position);