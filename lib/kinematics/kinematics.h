#pragma once

#include <prot.h>



class ball_class {
    private:

    float position, velocity, acceleration;

    public:

    ball_class();
    void atualize(float new_acceleration);
    void initialize();

    float get_position();
    float get_velocity();
    float get_acceleration();
};