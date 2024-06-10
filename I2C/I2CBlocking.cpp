// #include "I2CBlocking.hpp"

// using namespace HAM;

// I2CBlocking::I2CBlocking(I2C_HandleTypeDef* I2CDefinition):
// I2C{I2CDefinition}
// {
// }
// bool I2CBlocking::Write(const byte& address, byte byteToSend)
// {
//     return HAL_I2C_Master_Transmit(m_handle, address, &byteToSend, 1, HAL_MAX_DELAY) == HAL_OK;
// }

// bool I2CBlocking::Write(const byte& address, byte* bytes, const size_t& size)
// {
//     return HAL_I2C_Master_Transmit(m_handle, address, bytes, static_cast<uint16_t>(size), HAL_MAX_DELAY) == HAL_OK;
// }
// bool I2CBlocking::Read(const byte& address, byte* bytes, const size_t& size)
// {
//     return HAL_I2C_Master_Receive(m_handle, address, bytes, size, HAL_MAX_DELAY) == HAL_OK;
// }
// byte I2CBlocking::ReadByte(const byte& address)
// {
//     byte byteToRead;
//     HAL_I2C_Master_Receive(m_handle, address, &byteToRead, 1, HAL_MAX_DELAY);
//     return byteToRead;
// }

// I2CBlocking::~I2CBlocking()
// {
// }
