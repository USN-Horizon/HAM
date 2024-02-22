#pragma once
#include<i2c.h>
#include <HAMTypes.hpp>
namespace HAM
{
    class I2C
    {
    private:
        I2C_HandleTypeDef* m_handle;
    public:
        I2C(I2C_HandleTypeDef* I2CDefinition);
        bool Write(const byte& address, const byte buffer[]);

        ~I2C();
    };


}
