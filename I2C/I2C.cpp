#include "I2C.hpp"
using namespace HAM;

I2C::I2C(I2C_HandleTypeDef& I2CDefinition):
m_handle{&I2CDefinition}
{

      if (HAL_I2C_Init(m_handle) != HAL_OK)
      {
        DebugPrint("I2C Init failed\n");
        //Error handling
      }
}
HAL_StatusTypeDef I2C::WriteBlocking(const byte& address, byte* bytes, const size_t& size)
{
  return HAL_I2C_Master_Transmit(m_handle, address, bytes, static_cast<uint16_t>(size), HAL_MAX_DELAY);
}
HAL_StatusTypeDef I2C::ReadRegisterBlocking(const byte& address, byte& registerAddress, byte* bytes, const size_t& size)
{
  HAL_StatusTypeDef status = WriteBlocking(address, &registerAddress, 1);
  if(status == HAL_OK) return ReadBlocking(address, bytes, size);
  else return status;
}
HAL_StatusTypeDef I2C::ReadBlocking(const byte& address, byte* bytes, const size_t& size)
{
  return HAL_I2C_Master_Receive(m_handle, address, bytes, size, HAL_MAX_DELAY);
}
/**
 * @brief Writes data to a register on the I2C device in a blocking manner.
 * 
 * This function writes the specified data to a register on the I2C device
 * specified by the given address. The function blocks until the write operation
 * is complete.
 * 
 * @param address The address of the I2C device.
 * @param registerAddress The address of the register to write to.
 * @param bytes Pointer to the data to be written.
 * @param size The number of bytes to write.
 * @return The status of the write operation.
 */
HAL_StatusTypeDef I2C::WriteRegisterBlocking(const byte& address, byte& registerAddress, byte* bytes, const size_t& size)
{
  // byte byteSequence[] = {registerAddress, };
  // HAL_StatusTypeDef status = WriteBlocking(address, &registerAddress, 1);
  
}
HAL_StatusTypeDef I2C::ReadRegisterBlockingByte(const byte& address, const byte& registerAddress, byte& byteToReceive)
{
  byte reg = registerAddress;
  HAL_StatusTypeDef status = WriteBlockingByte(address, reg);
  if(status == HAL_OK) return ReadBlockingByte(address, byteToReceive);
  else return status;
}
HAL_StatusTypeDef I2C::WriteBlockingByte(const byte& address, byte& byteToSend)
{
  return HAL_I2C_Master_Transmit(m_handle, address, &byteToSend, 1, HAL_MAX_DELAY);
}
HAL_StatusTypeDef I2C::WriteRegisterBlockingByte(const byte& address, const byte& registerAddress, const byte& byteToSend)
{
  byte byteSequence[] = {registerAddress, byteToSend};
  return WriteBlocking(address, byteSequence, 2);
}

HAL_StatusTypeDef I2C::ReadBlockingByte(const byte& address, byte& byteToReceive)
{
  return HAL_I2C_Master_Receive(m_handle, address, &byteToReceive, 1, HAL_MAX_DELAY);
}
HAL_StatusTypeDef I2C::WriteAsync(const byte& address, byte* bytes, 
                                  const size_t& size)
{
  //m_onWriteAsyncComplete = {callbackFunction};
 //HAL_I2C_Master_Transmit_DMA(m_handle, address, bytes, size);
//  while (GetHandle()->State != HAL_I2C_STATE_READY);
 
  return HAL_OK;
}
HAL_StatusTypeDef I2C::ReadAsync(const byte& address, byte* bytes, 
                                 const size_t& size, const I2C::Callback& callbackFunction)
{
  m_onReadAsyncComplete = {callbackFunction};

}
const bool I2C::Busy() const
{
  return HAL_I2C_GetState(m_handle) != HAL_I2C_STATE_READY;
}
I2C::~I2C()
{
}