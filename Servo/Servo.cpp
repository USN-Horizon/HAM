#ifndef Servo.cpp

#include "Pwm.hpp"

class Servo
{
private:
    /* data */
    Pwm& pwmPin;
public:
    Servo(/* args */);
    ~Servo();

    void SetPosition(uint8_t angle, Pwm& pwmPin){
        uint16_t pulseWidth = map(angle, 0, 180, 1000, 2000);
        pwmPin 
    }
};

Servo::Servo(/* args */)
{
}

Servo::~Servo()
{
}

#endif