#pragma once

#include "prot.h"

const float COEF_OF_RESTITUTION = 0.5F; //the coefficient of restitution of the ball and the bottom, adimentional
const float TIME = DELAY/1000.0F; //the time beetween measurements from the sensor, in seconds
const float BAR_SIZE = 1.0F; //size of the bar, in meters

class ball_class {
    private:

    float position, velocity, acceleration;

    public:

    void atualize(float new_acceleration);
    
    float get_position();
    float get_velocity();
    float get_acceleration();
};