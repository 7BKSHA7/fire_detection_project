/**
 * @file      UART_interface.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the UART (Universal Asynchronous Receiver-Transmitter) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize, control, and communicate over UART using 
 *            both Polling (Blocking) and Interrupt (Non-Blocking) mechanisms.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_

#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../REG_MAP.h"
#include "UART_config.h"
#include "UART_private.h"


/*
    1- Mode Select -> Asynch / Synch 
    2- Stop Bit not -> 1Stop / 2 Stop 
    3- Parity Check status -> even / odd / disable 
    4- 
*/

// Initialization API
void UART_Init(Uart_Config_t Uart_Config);

// Polling (Blocking)API
void UART_SendBytePolling(u16 Data);
u16 UART_ReceiveBytePolling();
void UART_SendStringPolling(u8* String); // Characters 
void UART_ReceiveStringPolling(u8* Buffer, u8 Terminator);
void UART_SendBufferPolling(u8 * Buffer , u16 Length);//Raw Data 

// Interrupt API
void UART_SendByteInterrupt(u16 Data);

void UART_EnableRXInterrupt();
void UART_EnableTXInterrupt();
void UART_EnableREInterrupt();

void UART_DisableRXInterrupt();
void UART_DisableTXInterrupt();
void UART_DisableREInterrupt();

void UART_SetRXCallback(void (*PF)(u16));
void UART_SetTXCallback(void (*PF)(void));
void UART_SetRECallback(void (*PF)(void));

// Driver Control API
void UART_EnableRX();
void UART_EnableTX();
void UART_DisableRX();
void UART_DisableTX();



#endif
