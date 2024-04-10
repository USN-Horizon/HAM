#include "I2C.hpp"
#include <Uart.hpp>
#include <Debug.hpp>

using namespace HAM;

I2C::I2C(I2C_HandleTypeDef* I2CDefinition):
m_handle{I2CDefinition}
{

      if (HAL_I2C_Init(m_handle) != HAL_OK)
      {
        DebugPrint("I2C Init failed\n");
        //Error handling
      }
}
bool I2C::Write(const byte& address, byte& bytes, const size_t& size)
{
    return HAL_I2C_Master_Transmit(m_handle, address, &bytes, static_cast<uint16_t>(size), HAL_MAX_DELAY) == HAL_OK;
}
bool I2C::Read(const byte& address, byte& bytes, const size_t& size)
{
    return HAL_I2C_Master_Receive(m_handle, address, &bytes, size, HAL_MAX_DELAY) == HAL_OK;
}



I2C::~I2C()
{
}