#include <mode.h>

void mode0(mpu_sensor& mpu, led_strip& pixels, button_class& btn) {
    //This mode is the main mode, it is basically the ball.
    ball_class ball;
    COEF_OF_RESTITUTION = 0.5;
    while(btn.get_mode() == 0) {
        btn.atualize();
        //get data from the sensor
        sensors_event_t acc, gyro, temp;
        if(!mpu.getEvent(&acc, &gyro, &temp)) {
        Serial.println("uncessefull reading");
        }
    
    
        //atualize the ball position
        ball.atualize(-acc.acceleration.y);
    
        //get the led referent to the current position and light it
        show_unique_led(position_to_led(ball.get_position()), pixels, RED);
    }

}

void mode1(mpu_sensor& mpu, led_strip& pixels, button_class& btn) {
    //This mode is the second main mode, it is basically the ball, but as a bubble.
    ball_class ball;
    COEF_OF_RESTITUTION = 0.1;
    float COEF_OF_ATRICT = 0.5;
    while(btn.get_mode() == 1) {
        btn.atualize();
        //get data from the sensor
        sensors_event_t acc, gyro, temp;
        if(!mpu.getEvent(&acc, &gyro, &temp)) {
        Serial.println("uncessefull reading");
        }
    
    
        //atualize the ball position
        ball.atualize(acc.acceleration.y*COEF_OF_ATRICT);
    
        //get the led referent to the current position and light it
        show_unique_led(position_to_led(ball.get_position()), pixels, BLUE);
    }
}
void mode2(led_strip& pixels, button_class& btn){
    //This mode should be the collision
    ball_class ball1(1, -1, 0), ball2(0, 1, 0);
    while(btn.get_mode() == 2) {
        btn.atualize();
        ball1.atualize(0);
        ball2.atualize(0);
        if(ball1.get_position() < ball2.get_position()) {
            float tmp = ball1.get_position();
            ball1.position = ball2.position;
            ball2.position = tmp;
            ball1.velocity *= -COEF_OF_RESTITUTION;
            ball2.velocity *= -COEF_OF_RESTITUTION;
        } 
    
        //get the led referent to the current position and light it
        show_two_leds(pixels, position_to_led(ball1.get_position()), RED, 
                              position_to_led(ball2.get_position()), BLUE);
    }
}

void mode3(led_strip& pixels, button_class& btn ){
    //This mode shows all of the LEDs turned ON
    while(btn.get_mode() == 3) {
        btn.atualize();
        pixels.clear();
        for(int i = 0; i < NUM_LEDS; i++) {
            pixels.setPixelColor(i, GREEN);
        }
        pixels.show();
    }
}