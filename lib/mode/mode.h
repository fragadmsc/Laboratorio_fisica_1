#pragma once
#include <prot.h>
#include <kinematics.h>
#include <led.h>


void mode0(mpu_sensor& mpu, led_strip& pixels, button_class& btn);
void mode1(mpu_sensor& mpu, led_strip& pixels, button_class& btn);
void mode2();
void mode3();