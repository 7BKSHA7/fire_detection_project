/**
* @file    EventLogger_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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
