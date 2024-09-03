#pragma once
#include "Uart.hpp"
#include <bitset>
#define DEBUG 1
#ifdef DEBUG
static UART_HandleTypeDef DebugUSBUartDefinition
{
    .Instance = USART1,
    .Init{
        .BaudRate = 115200,
        .WordLength = UART_WORDLENGTH_8B,
        .Parity = UART_PARITY_NONE,
        .Mode = UART_MODE_TX_RX,
        .HwFlowCtl = UART_HWCONTROL_RTS_CTS,
        .OverSampling = UART_OVERSAMPLING_16,
    }
};
static HAM::Uart DebugUart{DebugUSBUartDefinition};

#define DebugPrint(VAR1) DebugUart.Print(VAR1) 
#define DebugPrintBinary(VAR1, N) DebugUart.Print(std::bitset<N>(VAR1).to_string())
#else
#define DebugPrint(VAR1)
#define DebugPrintBinary(VAR1, N) 
#endif
