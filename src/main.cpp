#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


#include <kinematics.h>


#define LED_PIN 13
#define NUM_LEDS 50

// put function declarations here:
int myFunction(int, int);

Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_MPU6050 mpu;


void setup() {

  //SERIAL
  Serial.begin(115200);

  //LED
  pixels.begin();

  //MPU
  if (!mpu.begin()) {
    while(true) {
      Serial.println("Failed to find MPU6050 chip");
    }
  } x 
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

}

void loop() {


  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.println(a.acceleration.z);

  delay(10);

  int led_number = ceil(25 + a.acceleration.z*2);
  pixels.clear();
  pixels.setPixelColor(led_number, 0xff0000);
  
  pixels.show();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}