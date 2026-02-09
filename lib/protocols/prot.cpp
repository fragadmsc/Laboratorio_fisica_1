#include <prot.h>

int position_to_led(float position) {
    //given the position of the ball, it finds the led correspondent to it
    float ratio = position/BAR_SIZE;
    return floor(ratio*NUM_LEDS);
}

int initialize_mpu(mpu_sensor& mpu){
    mpu.begin();
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

int initialize_leds(led_strip& pixels){
    pixels.begin();
}

int initialize_serial(HardwareSerial& serial){
    Serial.begin(115200);
}

