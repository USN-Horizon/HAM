#include "Pwm.hpp"
using namespace HAM;

Pwm::Pwm(const GpioPortPointer& gpioPort,  const GpioPin& pin, 
            TimerHandle timer, PwmChannel channel):
            Gpio{gpioPort, pin}, m_timerHandle{timer}, m_channel{channel}
{
    HAL_TIM_PWM_Start(&m_timerHandle, m_channel); // Maybe this should be put in the constructor?
}

void Pwm::SetPwm(const byte& value)
{
    
    __HAL_TIM_SET_COMPARE(&m_timerHandle, m_channel, value); // This?
}



