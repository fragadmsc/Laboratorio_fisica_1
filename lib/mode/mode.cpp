#include <mode.h>

void mode0(mpu_sensor& mpu, led_strip& pixels, ball_class& ball) {
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
void mode1(){

}
void mode2(){

}
void mode3(){

}