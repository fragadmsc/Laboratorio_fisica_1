//Arduino library
#include <Arduino.h>

//Personal librarires
#include <kinematics.h>
#include <led.h>
#include <prot.h>
#include <mode.h>

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
    button.read_buffer(analogRead(BUTTON_PIN), i);
    delay(DELAY/NUM_READS);
  }
  button.atualize();


  switch(button.get_cnt()) {
    case 0:
      mode0();
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

  //get data from the sensor
  sensors_event_t acc, gyro, temp;
  if(!mpu.getEvent(&acc, &gyro, &temp)) {
    Serial.println("uncessefull reading");
  }


  //atualize the ball position
  ball.atualize(acc.acceleration.y);
  
  //get the led referent to the current position and light it
  show_unique_led(position_to_led(ball.get_position()), pixels);

}
