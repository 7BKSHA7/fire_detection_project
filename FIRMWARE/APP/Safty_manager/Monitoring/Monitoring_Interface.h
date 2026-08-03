/**
 * @file      Monitoring_Interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the Monitoring subsystem.
 * @details   This file contains the function prototypes and public APIs for 
 *            the Monitoring module. It serves as the bridge between the 
 *            hardware sensors (LM35, MQ2), the timer scheduler, and the 
 *            application layer logic (Fire states and Event Logging).
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _MONITORING_INTERFACE_H_
#define _MONITORING_INTERFACE_H_

#include "Monitoring_Config.h"
#include "Monitoring_Private.h"

#include "../System/System_Interface.h"
#include "../Recovery/Recovery_Interface.h"
#include "../EventLogger/EventLogger_Interface.h"

#include "../../Fire_detection/Normal/Normal_Interface.h"
#include "../../Fire_detection/Warning/Warning_Interface.h"
#include "../../Fire_detection/Emergency/Emergency_Interface.h"
#include "../../Fire_detection/Fire/Fire_Interface.h"

#include "../../../HAL/LM35/LM35_interface.h"
#include "../../../HAL/MQ2/MQ2_interface.h"
#include "../../../MCAL/TIMER/TIMER_interface.h"
#include "../../../MCAL/GIE/GIE_Interface.h"


void MONITROING_init();
void MONITORING_update();
u8 MONITORING_get_values(u8 type);

#endif /* MONITORING_INTERFACE_H */
