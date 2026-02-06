#include "prot.h"

int position_to_led(float position) {
    //given the position of the ball, it finds the led correspondent to it
    float ratio = position/BAR_SIZE;
    return floor(ratio*NUM_LEDS);
}
