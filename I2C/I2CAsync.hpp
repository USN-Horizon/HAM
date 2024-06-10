// #pragma once

// #include "I2C.hpp"

// namespace HAM
// {
//     class I2CAsync: public I2C
//     {
//     private:
//         /* data */
//     public:
//         I2CAsync(I2C_HandleTypeDef* I2CDefinition);
//         bool Write(const byte& address, byte* bytes, const size_t& size);
//         bool Write(const byte& address, byte byteToSend);
//         bool Read(const byte& address, byte* bytes, const size_t& size);
//         bool Read(const byte& address, byte byteToRead);
//         byte ReadByte(const byte& address);

//         ~I2CAsync();
//     };

    
// }