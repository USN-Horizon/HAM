#pragma once
#include<i2c.h>
#include <HAMTypes.hpp>
#include <Debug.hpp>
#include <vector>
#include <array>
namespace HAM
{
    class I2C
    {
    private:
        I2C_HandleTypeDef* m_handle{nullptr};
    public:
        I2C(I2C_HandleTypeDef* I2CDefinition);
        bool Write(const byte& address, std::vector<byte>& bytes);
        bool Write(const byte& address, byte* bytes, const size_t& size);
        bool Read(const byte& address, byte* bytes, const size_t& size);
        bool Read(const byte& address, std::vector<byte>& bytes);
        ~I2C();
    };


}
