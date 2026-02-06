//Arduino library
#include <Arduino.h>

//Personal librarires
#include <kinematics.h>
#include <led.h>
#include <prot.h>


led_strip pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
mpu_sensor mpu;


void setup() {

  //SERIAL
  initialize_serial(Serial);

  //LED
  initialize_leds(pixels);

  //MPU
  if (!initialize_mpu(mpu)) {
    Serial.println("Failed to find MPU6050 chip");
    while(true) {delay(100);} 
  } 
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
