/**
 * @file      EventLogger_Interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the Event Logger subsystem.
 * @details   This file contains the function prototypes and public APIs for 
 *            the Event Logger module, allowing the main system to log various 
 *            states, sensor readings, and emergency events via UART.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef EVENTLOGGER_INTERFACE_H
#define EVENTLOGGER_INTERFACE_H

#include "EventLogger_Config.h"
#include "EventLogger_Private.h"

#include "../System/System_Interface.h"
#include "../Monitoring/Monitoring_Interface.h"

void EVENTLOGGER_init();

void EVENTLOGGER_normal();

void EVENTLOGGER_emergency();
void EVENTLOGGER_reset();
void EVENTLOGGER_acknowledged();
void EVENTLOGGER_fire();
void EVENTLOGGER_warning();


#endif /* EVENTLOGGER_INTERFACE_H */
