#pragma once
#include <HAMTypes.hpp>
namespace HAM
{
    void polynomialHelper(byte& crc, const byte& byteT)
    {
        crc ^= byteT;
        for(byte i = 0; i<8; i++)
            crc = crc & 0x80?(crc << 1) ^0x31: crc << 1;
    }

    /// @brief 
    /// Poly  : 0x31	x^8 + x^5 + x^4 + 1
	///	Init  : 0xFF
	/// Revert: false
	/// XorOut: 0x00
	/// Check : for 0xBE,0xEF CRC is 0x92
    /// @param MostSignificantByte 
    /// @param LeastSignificantByte 
    /// @param crc 
    /// @return 
    bool crc8(const byte& MostSignificantByte, 
              const byte& LeastSignificantByte,
              const byte& crc)
{
    byte crcResult = 0xFF;
    polynomialHelper(crcResult, MostSignificantByte);
    polynomialHelper(crcResult, LeastSignificantByte);
    return crc == crcResult;
}

    // byte crc = 0xFF;

};