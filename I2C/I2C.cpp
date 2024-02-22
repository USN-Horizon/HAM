    #include "I2C.hpp"
    using namespace HAM;

    I2C::I2C(I2C_HandleTypeDef* I2CDefinition):
    m_handle{I2CDefinition}
    {
          if (HAL_I2C_Init(m_handle) != HAL_OK)
          {
            //Error handling
          }
    }
    bool I2C::Write(const byte& address, const byte buffer[])
    {
      
    }
    
    I2C::~I2C()
    {
    }