#include "SHT30.hpp"

using namespace HAM;

SHT30::SHT30(I2C& i2c, const byte& address):
m_i2c{&i2c}, m_address{address << 1}
{
}


float SHT30::GetTemperature()
{
   byte bytes[6]{0};
//    byte command[2] ={0x2c, 0x06};
   byte command[sizeof( Register::HighMeasurePrepStretch)];
   std::copy(std::begin(Register::HighMeasurePrepStretch), std::end(Register::HighMeasurePrepStretch), std::begin(command));
   m_i2c->Write(m_address, command, 2);
   m_i2c->Read(m_address, bytes, 6);
   // TODO CRC check
   uint16_t temperature = bytes[0] << 8 | bytes[1];
   return -45.0f + 175.0f * static_cast<float>(temperature)/65535.0f;
}


SHT30::~SHT30()
{
}