#include "Temperature.hpp"
using namespace HAM;
using namespace BMI088;
using namespace BMI088::TemperatureRegisters;

Temperature::Temperature( I2C& i2c,  const byte& address, const ISensorAsync::Callback& callback):
                        m_i2c{&i2c}, m_address{address}, 
                        ISensorAsync{callback}
{
}

bool Temperature::initiate()
{

}

bool Temperature::startReading()
{
    byte byteToSend[] = {TemperatureSensorAddress};
    // m_i2c->WriteAsync(m_address, byteToSend, 1, [this](){
    //     m_i2c->ReadAsync(m_address, m_buffer, 2, [this](){
    //         onReadingComplete();
    //     });
    // });
}
void Temperature::onReadingComplete()
{
    uint16_t tempUint11 = (m_buffer[0]* 8) + (m_buffer[1]/32); 
    if (tempUint11 > 1023) tempUint11 =- 2048;
    m_temperature = tempUint11* 0.125/m_buffer[1]+ 23.0;
    onNewReadingAvailable();
}

float Temperature::getTemperature(){return m_temperature;}