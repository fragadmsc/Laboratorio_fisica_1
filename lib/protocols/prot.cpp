#include "prot.h"

int position_to_led(float position) {
    float ratio = position/BAR_SIZE;
    return floor(ratio*NUM_LEDS);
}
