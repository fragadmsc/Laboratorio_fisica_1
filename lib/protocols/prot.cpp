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
    return true;
}

bool initialize_serial(HardwareSerial& serial){
    //returns true if initializations was successfull and false if not
    serial.begin(115200);
    return true;
}

void button_class::atualize() {
    for(int i = 0; i < NUM_READS; i++) {
        read_buffer(i, analogRead(BUTTON_PIN));
        delay(DELAY/NUM_READS);
    }
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

int button_class::get_mode() {
    return cnt = cnt%NUM_MODES;
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

void show_unique_led(int led, led_strip& strip, long long color) {
    //sets the value of a single led and show it
    strip.clear();
    strip.setPixelColor(led, color);
    strip.show();
}


void show_two_leds(led_strip& strip, int led1,  long long color1, int led2,  long long color2) {
    strip.clear();
    strip.setPixelColor(led1, color1);
    strip.setPixelColor(led2, color2);
    strip.show();
}