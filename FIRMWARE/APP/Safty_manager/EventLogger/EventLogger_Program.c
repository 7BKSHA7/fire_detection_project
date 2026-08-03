/**
 * @file      EventLogger_Program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Event Logger subsystem.
 * @details   This file contains the logic for logging system events, states, 
 *            and sensor readings over UART to an external monitor or PC.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "EventLogger_Interface.h"

Uart_Config_t Uart_Config_event_logger = 
{
    .ModeSelect = Uart_AsynchronousMode,
    .StopBitSelect = Uart_1StopBit,
    .ParitySelect = Uart_ParityDisabled,
    .SizeCharacterSelect = Uart_8BitSize,
    .SpeedMode = Uart_NormalSpeed,
    .BaudRate = 9600,
    .InterruptSelect = Uart_InterruptDisabled,
    .EnbaleSelect = Uart_EnableRxAndTx
};
void EVENTLOGGER_init()
{

    UART_Init(Uart_Config_event_logger);
    UART_SendStringPolling("system initialized\r\n");
    UART_SendStringPolling("ready to monitor\r\n");

}   

/*
SYSTEM STARTED

WARNING LEVEL 1

SMOKE DETECTED

FIRE ALARM

USER ACKNOWLEDGED

SYSTEM RESET
*/

// must be done win uart is done 
void EVENTLOGGER_normal()
{
    UART_SendStringPolling("temp  : ");
    UART_SendBytePolling(MONITORING_get_values(temp_values));
    UART_SendStringPolling("\r\n");

    UART_SendStringPolling("smoke : ");
    UART_SendBytePolling(MONITORING_get_values(smoke_values));
    UART_SendStringPolling("\r\n");
}

void EVENTLOGGER_warning()
{
    UART_SendStringPolling("WARNING LEVEL 1\r\n");
}

void EVENTLOGGER_fire()
{
    UART_SendStringPolling("FIRE ALARM\r\n");
}

void EVENTLOGGER_acknowledged()
{
    UART_SendStringPolling("USER ACKNOWLEDGED\r\n");
}

void EVENTLOGGER_reset()
{
    UART_SendStringPolling("SYSTEM RESET\r\n");
}

void EVENTLOGGER_emergency()
{
    UART_SendStringPolling("EMERGENCY\r\n");
}
