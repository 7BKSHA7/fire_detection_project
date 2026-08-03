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

#include "../../LIB/STD_TYPES.h"
#include "UART_private.h"
#include "UART_config.h"

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

// Driver Control API
void UART_EnableRX();
void UART_EnableTX();
void UART_DisableRX();
void UART_DisableTX();



#endif