/**
* @file    Monitoring_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef _MONITORING_INTERFACE_H_
#define _MONITORING_INTERFACE_H_

#include "Monitoring_Config.h"
#include "Monitoring_Private.h"
#include "../System/System_Interface.h"

#include "../../../HAL/LM35/LM35_interface.h"
#include "../../../HAL/MQ2/MQ2_interface.h"
#include "../../../MCAL/TIMER/TIMER_interface.h"
#include "../../../MCAL/GIE/GIE_Interface.h"


void MONITROING_init();
void MONITORING_update();


#endif /* MONITORING_INTERFACE_H */
