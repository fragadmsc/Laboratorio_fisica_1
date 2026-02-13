//Arduino library
#include <Arduino.h>

//Personal librarires
#include <prot.h>
#include <mode.h>

const int DEBUG = 1;

led_strip pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
mpu_sensor mpu;
button_class button;

void setup() {
  //SERIAL
  initialize_serial(Serial);

  //LED
  initialize_leds(pixels);

  //MPU
  if (!initialize_mpu(mpu)) {
    while(true) {
      Serial.println("Failed to find MPU6050 chip");
      delay(100);
    } 
  }

  //BUTTON
  button.initialize();
}

void loop() {

  if(DEBUG) {
    Serial.println("------------");
    Serial.println(button.get_mode());
  }

  switch(button.get_mode()) {
    case 0:
      mode0(mpu, pixels, button);
      break;
    case 1:
      mode1(mpu, pixels, button);
      break;
    case 2:
      mode2(pixels, button);
      break;
    case 3:
      mode3();
      break;
    default:
      break;
  }
}
