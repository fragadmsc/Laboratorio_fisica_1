#pragma once

#include <prot.h>

class ball_class {
    public:

    float position, velocity, acceleration;

    ball_class();
    ball_class(float p, float v, float a);
    void atualize(float new_acceleration);
    void initialize();

    float get_position();
    float get_velocity();
    float get_acceleration();
};