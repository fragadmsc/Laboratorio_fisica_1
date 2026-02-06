//Arduino library
#include <Arduino.h>

//Personal librarires
#include <kinematics.h>
#include <led.h>
#include <prot.h>

led_strip pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
mpu_sensor mpu;
ball_class ball;

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

  //BALL
}

void loop() {

  //get data from the sensor
  sensors_event_t acc, gyro;
  mpu.getEvent(&acc, &gyro, nullptr);

  //atualize the ball position
  ball.atualize(acc.acceleration.z);
  
  //get the led referent to the current position and light it
  show_unique_led(position_to_led(ball.get_position()), pixels);

  //delay
  delay(DELAY);
}
