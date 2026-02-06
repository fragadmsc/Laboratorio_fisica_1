#pragma once

#include "prot.h"

#define LED_PIN 13
#define NUM_LEDS 50

const int COLOR = 0xFFFF00;

void show_unique_led(int led, led_strip& strip);