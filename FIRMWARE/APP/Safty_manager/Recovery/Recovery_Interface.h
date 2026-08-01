/**
* @file    Recovery_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef RECOVERY_INTERFACE_H
#define RECOVERY_INTERFACE_H

#include "Recovery_Config.h"
#include "Recovery_Private.h"

#include "../System/System_Interface.h"
#include "../Monitoring/Monitoring_Interface.h"
#include "../../../MCAL/EXTI/EXTI_interface.h"

void RECOVERY_init();
u8 RECOVERY_update();
void RECOVERY_button_pressed();


#endif /* RECOVERY_INTERFACE_H */
