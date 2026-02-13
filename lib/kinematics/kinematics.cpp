#include <kinematics.h>

void ball_class::atualize(float new_acceleration) {
    //atualizes the position, velocity and acceleration of the ball, given the new acceleration
    position += velocity*TIME;
    velocity += acceleration*TIME;
    acceleration = new_acceleration;
    if(position > BAR_SIZE) {
        //invert the velocity of the ball
        //put the ball in the correct range again
        position = BAR_SIZE;
        velocity = -velocity*COEF_OF_RESTITUTION;
    } else if(position < 0) {
        position = 0;
        velocity = -velocity*COEF_OF_RESTITUTION;
    }
}

float ball_class::get_position() {
    return position;
}

float ball_class::get_velocity() {
    return velocity;
}

float ball_class::get_acceleration() {
    return acceleration;
}

ball_class::ball_class() {
    position = 0;
    velocity = 0;
    acceleration = 0;
}