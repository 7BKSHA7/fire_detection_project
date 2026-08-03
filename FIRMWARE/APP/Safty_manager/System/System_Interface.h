/**
 * @file      System_Interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the core System application layer.
 * @details   This file contains the function prototypes for the main system 
 *            initialization and the continuous update loop. It acts as the 
 *            central hub including all necessary HAL and MCAL drivers.
 * @version   1.0.0
 * @date      3 August 2026
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

#include "../../../MCAL/UART/UART_Interface.h"
#include "../../../MCAL/EXTI/EXTI_interface.h"

void SYSTEM_init ();
void SYSTEM_update();

#endif /* SYSTEM_INTERFACE_H */
