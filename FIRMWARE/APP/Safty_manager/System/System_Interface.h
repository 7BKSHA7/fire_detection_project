/**
* @file    System_Interface.h
* @author beshoy  
* @author beshoy
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef _SYSTEM_INTERFACE_H_
#define _SYSTEM_INTERFACE_H_

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/COMMON_MACROS.h"
#include "System_Config.h"
#include "System_Private.h"

#include "../../../HAL/BUTTON/BUTTON_interface.h"
#include "../../../HAL/LED/LED_interface.h"
#include "../../../HAL/LCD/LCD_interface.h"
#include "../../../HAL/LM35/LM35_interface.h"
#include "../../../HAL/MQ2/MQ2_interface.h"
#include "../../../HAL/BUZZER/BUZZER_interface.h"
#include "../../../MCAL/EXTI/EXTI_interface.h"

void SYSTEM_init ();
void SYSTEM_update();

#endif /* SYSTEM_INTERFACE_H */
