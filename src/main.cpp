//Arduino library
#include <Arduino.h>

//Personal librarires
#include <kinematics.h>
#include <led.h>
#include <prot.h>
#include <mode.h>

const int DEBUG = 1;

led_strip pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
mpu_sensor mpu;
ball_class ball;
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

  //BALL
  ball.initialize();

  //BUTTON
  button.initialize();
}

void loop() {

  //See if the button was pressed
  for(int i = 0; i < NUM_READS; i++) {
    button.read_buffer(i, analogRead(BUTTON_PIN));
    delay(DELAY/NUM_READS);
  }
  button.atualize();

  if(DEBUG) {
    Serial.println("------------");
    Serial.println(button.get_cnt());
  }

  switch(button.get_cnt()%NUM_MODES) {
    case 0:
      mode0(mpu, pixels, ball);
      break;
    case 1:
      mode1();
      break;
    case 2:
      mode1();
      break;
    case 3:
      mode1();
      break;
  }


}
