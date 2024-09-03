#pragma once
#include <HAMTypes.hpp>
namespace HAM
{
    namespace BMI088
    {
        static const uint8_t ACC_CHIP_ID_ADDR = 0x00;
        namespace AccelerometerRegisters
        {
            namespace ACC_SOFT_RESET
            {
                const static byte Address = 0x7E;
            };
            namespace ACC_PWR_CTRL
            {
                const static byte Address = 0x7D;
            };
            namespace ACC_CONF
            {
                const static byte Address = 0x40;
                enum OutputDataRate: byte
                {
                    Hz12_5 = 0x05,
                    Hz25 = 0x06,
                    Hz50 = 0x07,
                    Hz100 = 0x08,
                    Hz200 = 0x09,
                    Hz400 = 0x0A,
                    Hz800 = 0x0B,
                    Hz1600 = 0x0C,
                };
                union Register
                {
                    struct
                    {
                        byte acc_odr: 4;
                        byte acc_bwp: 3;
                        byte reserved: 1;
                    } Fields;
                    byte Value;
                };
            };
            namespace ACC_RANGE
            {
                const static byte Address = 0x41;
                enum Range: byte
                {
                    g3 = 0x00,
                    g6 = 0x01,
                    g12 = 0x02,
                    g24 = 0x03,
                };
                union Register
                {
                    struct
                    {
                        byte acc_range: 2;
                        byte reserved: 6;
                    } Fields;
                    byte Value;
                };
            };
            namespace InterruptPin
            {
                enum Direction
                {
                    Input,
                    Output
                };
                enum Behaviour
                {
                    PushPull,
                    OpenDrain
                };
                enum State
                {
                    Low,
                    High
                };
                struct Config
                {
                    Direction direction;
                    Behaviour behaviour;
                    State state;
                };
            };
            namespace INTX_IO_CONF
            {
                union Register
                {
                    struct
                    {
                        byte reserved2: 3;
                        byte intx_in: 1;
                        byte intx_out: 1;
                        byte intx_od: 1;
                        byte intx_lvl: 1;
                        byte reserved: 1;
                    } Fields;
                    byte Value;
                };
            };
            namespace INT1_IO_CONF
            {
                const static byte Address = 0x53;
                // union Register
                // {
                //     struct
                //     {
                //         byte reserved2: 3;
                //         byte int1_in: 1;
                //         byte int1_out: 1;
                //         byte int1_od: 1;
                //         byte int1_lvl: 1;
                //         byte reserved: 1;
                //     } Fields;
                //     byte Value;
                // };
            };
            namespace INT2_IO_CONF
            {
                const static byte Address = 0x54;
                // union Register
                // {
                //     struct
                //     {
                //         byte reserved2: 3;
                //         byte int2_in: 1;
                //         byte int2_out: 1;
                //         byte int2_od: 1;
                //         byte int2_lvl: 1;
                //         byte reserved: 1;
                //     } Fields;
                //     byte Value;
                // };
            };
            namespace INT1_INT2_MAP_DATA
            {
                const static byte Address = 0x58;
                union Register
                {
                    struct
                    {
                        byte reserved3: 1;
                        byte int2_drdy: 1;
                        byte reserved2: 3;
                        byte int1_drdy: 1;
                        byte reserved: 2;
                    } Fields;
                    byte Value;
                };
            };
            namespace ACC_DATA
            {
                const static byte Address = 0x12;
            };
            // namespace Addresses
            // {
            //     static const uint8_t ACC_FATAL_ERR_ADDR = 0x02;
            //     static const uint8_t ACC_ERR_CODE_ADDR = 0x02;
            //     static const uint8_t ACC_DRDY_ADDR = 0x03;
            //     static const uint8_t ACC_CONF = 0x40;
            //     static const uint8_t ACC_RANGE_ADDR = 0x41;
            //     static const uint8_t ACC_INT1_IO_CTRL_ADDR = 0x53;
            //     static const uint8_t ACC_INT2_IO_CTRL_ADDR = 0x54;
            //     static const uint8_t ACC_INT1_DRDY_ADDR = 0x58;
            //     static const uint8_t ACC_INT2_DRDY_ADDR = 0x58;
            //     static const uint8_t ACC_SELF_TEST_ADDR = 0x6D;
            //     static const uint8_t ACC_PWR_CONF_ADDR = 0x7C;
            //     static const uint8_t ACC_PWR_CTRL_ADDR = 0x7D;
            //     static const uint8_t ACC_SOFT_RESET_ADDR = 0x7E;
            //     static const uint8_t ACC_ACCEL_DATA_ADDR = 0x12;
            //     static const uint8_t ACC_TEMP_DATA_ADDR = 0x22;
            // }
            namespace ACC_PWR_CONF
            {
                const static byte Address = 0x7C;
            } // namespace name
            
     
        }
        namespace GyroscopeRegisters
        {
            namespace Addresses
            {
                static const uint8_t GYRO_CHIP_ID_ADDR = 0x00;
                static const uint8_t GYRO_RANGE_ADDR = 0x0F;
                static const uint8_t GYRO_ODR_ADDR = 0x10;
                static const uint8_t GYRO_SOFT_RESET_ADDR = 0x14;
                static const uint8_t GYRO_INT_CNTRL_ADDR = 0x15;
                static const uint8_t GYRO_INT3_IO_CTRL_ADDR = 0x16;
                static const uint8_t GYRO_INT4_IO_CTRL_ADDR = 0x16;
                static const uint8_t GYRO_INT3_DRDY_ADDR = 0x18;
                static const uint8_t GYRO_INT4_DRDY_ADDR = 0x18;
                static const uint8_t GYRO_DATA_ADDR = 0x02;
            }
        }
        namespace TemperatureRegisters
        {
            const static byte TemperatureSensorAddress = 0x22;
        };
    }
}