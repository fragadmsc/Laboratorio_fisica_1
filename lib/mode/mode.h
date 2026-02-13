#pragma once
#include <prot.h>
#include <kinematics.h>


void mode0(mpu_sensor& mpu, led_strip& pixels, button_class& btn);
void mode1(mpu_sensor& mpu, led_strip& pixels, button_class& btn);
void mode2(led_strip& pixels, button_class& btn);
void mode3();