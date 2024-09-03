#pragma once 
#include <ISensorAsync.hpp>
#include <ITemperature.hpp>
#include <I2C.hpp>
#include "Registers.hpp"
namespace HAM
{
    namespace BMI088
    {
        using namespace TemperatureRegisters;
        class Temperature: public ISensorAsync, ITemperature
        {
        private:
            I2C* m_i2c;
            byte m_address;
            float m_temperature;
            byte m_buffer[2];
        public:
            Temperature( I2C& i2c, const byte& address,
            const ISensorAsync::Callback& onNewReadingAvailable);
            bool initiate() final;
            bool startReading() final;
            void onReadingComplete() final;
            float getTemperature() final;
        };
    }
}