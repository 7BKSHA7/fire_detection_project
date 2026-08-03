/**
 * @file      UART_private.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the UART Driver.
 * @details   This file contains internal macros representing the microcontroller 
 *            register bits for UART (UCSRA, UCSRB, UCSRC), configuration constants, 
 *            and the main configuration structure used by the driver.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H
#include "../../LIB/STD_TYPES.h"


// UCSRA
#define Uart_RXC  7 
#define Uart_TXC  6
#define Uart_UDRE 5
#define Uart_FE   4 
#define Uart_DOR  3
#define Uart_PE   2 
#define Uart_U2X  1 
#define Uart_MPCM 0 

#define Uart_NormalSpeed  0 
#define Uart_DoubleSpeed  1 

// UCSRB
#define Uart_RXCIE  7 
#define Uart_TXCIE  6
#define Uart_UDRIE  5
#define Uart_RXEN   4 
#define Uart_TXEN   3
#define Uart_UCSZ2  2 
#define Uart_RXB8   1 
#define Uart_TXB8   0 


// UCSRC
#define Uart_URSEL  7 
#define Uart_UMSEL  6
#define Uart_UPM1   5
#define Uart_UPM0   4 
#define Uart_USBS   3
#define Uart_UCSZ1  2 
#define Uart_UCSZ0  1 
#define Uart_UCPOL  0 


#define Uart_AsynchronousMode   0
#define Uart_SynchronousMode    1


#define Uart_ParityDisabled 0 
#define Uart_ParityEven     1 
#define Uart_ParityOdd      2

#define Uart_1StopBit       0
#define Uart_2StopBit       1


#define Uart_5BitSize       0
#define Uart_6BitSize       1
#define Uart_7BitSize       2
#define Uart_8BitSize       3
#define Uart_9BitSize       4

#define Uart_EnableRxOnly   0
#define Uart_EnableTxOnly   1 
#define Uart_EnableRxAndTx  2


#define Uart_InterruptDisabled      0  
#define Uart_InterruptRxOnly        1   
#define Uart_InterruptTxOnly        2   
#define Uart_InterruptUdreOnly      3   
#define Uart_InterruptRxTx          4   
#define Uart_InterruptRxUdre        5  
#define Uart_InterruptTxUdre        6   
#define Uart_InterruptAll           7  


#define FCPU   8000000UL

typedef struct 
{
    u8 ModeSelect; 
    u8 StopBitSelect;
    u8 ParitySelect;
    u8 SizeCharacterSelect;
    u8 SpeedMode;
    u32 BaudRate;
    u8 InterruptSelect;
    u8 EnbaleSelect;
}Uart_Config_t;

// ISR Vectors
void __vector_13(void) __attribute__((signal,used)); // RX Complete
void __vector_14(void) __attribute__((signal,used)); // UDR Empty
void __vector_15(void) __attribute__((signal,used)); // TX Complete

#endif
