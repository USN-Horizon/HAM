#include "Accelerometer.hpp"

using namespace HAM::BMI088;
using namespace AccelerometerRegisters;

Accelerometer::Accelerometer(I2C& i2c, const byte& address, 
        const Config& config, const ISensorAsync::Callback& onNewReadingAvailable):
        m_i2c{&i2c}, m_address{(address << 1)}, 
        ISensorAsync{onNewReadingAvailable}
{
    // initiate();
    // setOutputDataRate(config.AccelerometerODR);
}

// Page 13 in datasheet quickstart guide
//
bool Accelerometer::initiate()
{
    //Wait 1ms for sensor to boot
    m_i2c->WriteRegisterBlockingByte(m_address, ACC_PWR_CTRL::Address, 0x04);
   //Wait 450 us

}
/**
 * @brief Performs a software reset of the BMI088 accelerometer.
 *
 * This function sends a command to the BMI088 accelerometer to perform a software reset.
 * After the reset, the accelerometer will be in its default state.
 * Page 25 of datasheet
 */
void Accelerometer::softReset()
{
    m_i2c->WriteRegisterBlockingByte(m_address, ACC_SOFT_RESET::Address, 0xB6);
}

void Accelerometer::setOutputDataRate(const ACC_CONF::OutputDataRate& odr)
{
    ACC_CONF::Register registerValue;   
    m_i2c->ReadRegisterBlockingByte(m_address, ACC_CONF::Address, registerValue.Value);
    registerValue.Fields.acc_odr = odr;
    m_i2c->WriteRegisterBlockingByte(m_address, ACC_CONF::Address, registerValue.Value);
}
void Accelerometer::setRange(const ACC_RANGE::Range& range)
{
    ACC_RANGE::Register registerValue;
    m_i2c->ReadRegisterBlockingByte(m_address, ACC_RANGE::Address, registerValue.Value);
    registerValue.Fields.acc_range = range;
    m_i2c->WriteRegisterBlockingByte(m_address, ACC_RANGE::Address, registerValue.Value);
    m_accelerationConversion = 32768.0f*1000.0f*(1 << range + 1);
}
void Accelerometer::setInterruptPin(const byte pin, const InterruptPin::Config& config)
{
    if(pin > 2 || pin == 0) return;
    INT1_INT2_MAP_DATA::Register mapRegisterValue;
    m_i2c->ReadRegisterBlockingByte(m_address, INT1_INT2_MAP_DATA::Address, mapRegisterValue.Value);
    INTX_IO_CONF::Register registerValue;
    const byte address = pin == 1 ? INT1_IO_CONF::Address :INT2_IO_CONF::Address; 
    registerValue.Fields.intx_in = config.direction;
    registerValue.Fields.intx_lvl = config.state;
    registerValue.Fields.intx_od = config.behaviour;
    if(pin == 1) mapRegisterValue.Fields.int1_drdy = config.direction;
    else if(pin == 2) mapRegisterValue.Fields.int2_drdy = config.direction;
    if(config.direction == InterruptPin::Direction::Output)
    {
        registerValue.Fields.intx_out = 1;
        registerValue.Fields.intx_in = 0;
    }
    else if(config.direction == InterruptPin::Direction::Input)
    {
        registerValue.Fields.intx_out = 0;
        registerValue.Fields.intx_in = 1;
    }
    m_i2c->WriteRegisterBlockingByte(m_address, address, registerValue.Value);
    m_i2c->WriteRegisterBlockingByte(m_address, INT1_INT2_MAP_DATA::Address, mapRegisterValue.Value);
}

float Accelerometer::X(){return m_xyz[0];}
float Accelerometer::Y(){return m_xyz[1];}
float Accelerometer::Z(){return m_xyz[2];}
float Accelerometer::TotalAcceleration()
{

}

bool Accelerometer::startReading()
{
    byte byteToSend[]{ACC_DATA::Address};
    m_i2c->WriteAsync(m_address, byteToSend, 1, [&](){
        m_i2c->ReadAsync(m_address, m_buffer, 6,[&](){
            onReadingComplete();
        });
    });
}
void Accelerometer::onReadingComplete()
{
    m_xyz[0] = (m_buffer[3] << 8 | m_buffer[2]) * m_accelerationConversion;
    m_xyz[1] = (m_buffer[5] << 8 | m_buffer[4]) * m_accelerationConversion;
    m_xyz[2] = (m_buffer[7] << 8 | m_buffer[6]) * m_accelerationConversion;
    onNewReadingAvailable();
}

Accelerometer::~Accelerometer()
{
}