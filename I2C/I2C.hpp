#pragma once
#include<i2c.h>
#include <HAMTypes.hpp>
#include <Debug.hpp>
#include <vector>
#include <array>
#include <functional>

namespace HAM
{

    class I2C
    {
    public:
        typedef std::function<void()> Callback; 
    protected:
        I2C_HandleTypeDef* m_handle{nullptr};
        Callback m_onWriteAsyncComplete;
        Callback m_onReadAsyncComplete;
    public:
        I2C(I2C_HandleTypeDef& I2CDefinition);
        // Blocking
        HAL_StatusTypeDef WriteBlocking(const byte& address, byte* bytes, const size_t& size);
        HAL_StatusTypeDef ReadBlocking(const byte& address, byte* bytes, const size_t& size);
        HAL_StatusTypeDef WriteRegisterBlocking(const byte& address, byte& registerAddress, byte* bytes, const size_t& size);
        HAL_StatusTypeDef ReadRegisterBlocking(const byte& address, byte& registerAddress, byte* bytes, const size_t& size);

        HAL_StatusTypeDef WriteBlockingByte(const byte& address, byte& byteToSend);
        HAL_StatusTypeDef ReadBlockingByte(const byte& address, byte& byteToReceive);
        HAL_StatusTypeDef WriteRegisterBlockingByte(const byte& address, const byte& registerAddress, const byte& byteToSend);
        HAL_StatusTypeDef ReadRegisterBlockingByte(const byte& address, const byte& registerAddress, byte& byteToReceive);


        // Non-blocking
        HAL_StatusTypeDef WriteAsync(const byte& address, byte* bytes, const size_t& size, 
                                    const I2C::Callback& callbackFunction);
        HAL_StatusTypeDef ReadAsync(const byte& address, byte* bytes, const size_t& size, 
                                    const I2C::Callback& callbackFunction);

        void OnWriteAsyncComplete(){ 
            if(m_onWriteAsyncComplete) m_onWriteAsyncComplete();
            };
        void OnReadAsyncComplete(){
            if(m_onReadAsyncComplete)m_onReadAsyncComplete();
            };
        const bool Busy () const;
        const I2C_HandleTypeDef* GetHandle() const{return m_handle;};

        // HAL_StatusTypeDef Write(const byte& address, std::vector<byte>& bytes);
        // HAL_StatusTypeDef Read(const byte& address, std::vector<byte>& bytes);
        // virtual bool Write(const byte& address, byte* bytes, const size_t& size) = 0;
        // virtual bool Write(const byte& address, byte byteToSend) = 0;
        // virtual bool Read(const byte& address, byte* bytes, const size_t& size) = 0;
        // virtual byte ReadByte(const byte& address) = 0;
        ~I2C();
    };


}
