#include "Gpio.hpp"
using namespace HAM;

Gpio::Gpio(const GpioPortPointer& gpioPort, const GpioPin& pin):
   m_pin{Pin{gpioPort, pin}}
{
}
Gpio::Gpio(const Pin& pin):
   m_pin{pin}
{}
Gpio::~Gpio()
{
}

void Gpio::Toggle()
{
    HAL_GPIO_TogglePin(m_pin.port, m_pin.pinNumber);
}
void Gpio::Set(const bool& state)
{
    HAL_GPIO_WritePin(m_pin.port, m_pin.pinNumber, static_cast<GPIO_PinState>(state));
}
const bool Gpio::Get() const
{
    return static_cast<bool>(HAL_GPIO_ReadPin(m_pin.port, m_pin.pinNumber));
}
