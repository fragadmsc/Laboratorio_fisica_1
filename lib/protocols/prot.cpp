#include <prot.h>

int position_to_led(float position) {
    //given the position of the ball, it finds the led correspondent to it
    float ratio = position/BAR_SIZE;
    int led = floor(ratio*NUM_LEDS);
    if(led > 59) led = 59;
    if(led < 0) led = 0;
    return led;
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

void button_class::atualize() {
    int sum = 0;
    for(short int i = 0; i < NUM_READS; i++) {
        sum += buffer[i];
    }
    if(sum >= NUM_READS*MAX_ANALOG_READ - TOLERANCE_ANALOG_READ) {
        if(prev == 0) cnt++;
        prev = 1;
    } else {
        prev = 0;
    }
}

int button_class::get_cnt() {
    return cnt;
}

void button_class::read_buffer(int position, int value) {
    buffer[position] = value;
}

void button_class::initialize() {
    cnt = 0;
    for(int i = 0; i < NUM_READS; i++) {
        buffer[i] = 0;
    }
    pinMode(BUTTON_PIN, INPUT);
}