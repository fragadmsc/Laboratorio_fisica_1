#include "led.h"


void show_unique_led(int led, led_strip& strip) {
    //sets the value of a single led and show it
    strip.clear();
    strip.setPixelColor(led, COLOR);
    strip.show();
}