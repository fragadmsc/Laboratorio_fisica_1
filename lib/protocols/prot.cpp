#include <prot.h>

int position_to_led(float position) {
    //given the position of the ball, it finds the led correspondent to it
    float ratio = position/BAR_SIZE;
    return floor(ratio*NUM_LEDS);
}

bool initialize_mpu(mpu_sensor& mpu){
    //returns true if initializations was successfull and false if not
    if(mpu.begin() == false) return false;
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    return true;
}

bool initialize_leds(led_strip& pixels){
    //returns true if initializations was successfull and false if not
    pixels.begin();
    pixels.clear();
    pixels.show();
    return 0;
}

bool initialize_serial(HardwareSerial& serial){
    //returns true if initializations was successfull and false if not
    serial.begin(115200);
    return 0;
}

