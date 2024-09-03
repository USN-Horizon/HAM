#pragma once 
#include <ISensorAsync.hpp>
#include <IAccelerometer.hpp>
#include <I2C.hpp>
#include "Registers.hpp"
#include <Debug.hpp>
namespace HAM
{
    namespace BMI088
    {
        using namespace AccelerometerRegisters;
        class Accelerometer: public ISensorAsync, IAccelerometer
        {
        private:
            I2C* m_i2c;
            byte m_address;
            float m_xyz[3] = {0};
            byte m_buffer[6] = {0};
            float m_accelerationConversion{0.1};
        public:
            struct Config
            {
                ACC_CONF::OutputDataRate AccelerometerODR;
            };
            Accelerometer(I2C& i2c, const byte& address, const Config& config,
                          const ISensorAsync::Callback& onNewReadingAvailable);
            bool initiate() final;
            void softReset();
            void setOutputDataRate(const ACC_CONF::OutputDataRate& odr);
            void setRange(const ACC_RANGE::Range& range);
            void setInterruptPin(const byte pin, const InterruptPin::Config& config);
            bool startReading() final;
            void onReadingComplete() final;
            void BlockingRead();
            // void onNewReadingAvailable() final;
            float X() final;
            float Y() final;
            float Z() final;
            float TotalAcceleration() final;
            ~Accelerometer();
        };
    }
}




