#pragma once
#include <Debug.hpp>
#include <I2C.hpp>
// #include <temp.hpp>
namespace HAM
{

    namespace Register
    {
        union 
        {
            struct
            {
                uint16_t WriteCheckSumStatus:1;
                uint16_t Command: 1;
                uint16_t Reserved1: 2;
                uint16_t SystemResetDetected: 1;
                uint16_t Reserved2: 4;
                uint16_t TemperatureTrackingAlert: 1;
                uint16_t HumidityTrackingAlert: 1;
                uint16_t Reserved3: 1;
                uint16_t HeaterStatus: 1;
                uint16_t Reserved4: 4;
                uint16_t AlertPending: 1;
            } Bits;
        } Status;
        const byte HighMeasurePrepStretch[2] = {0x2c, 0x06};
    }
    
    class SHT30
    {
    private:
        I2C* m_i2c;
        byte m_address;
    public:
        SHT30(I2C& i2c, const byte& address = 0x44);
        float GetTemperature();
        ~SHT30();
    };
    

    

}

