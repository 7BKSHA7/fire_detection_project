/**
 * @file      Recovery_Interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the Recovery subsystem.
 * @details   This file contains the function prototypes and public APIs for 
 *            the Recovery module, allowing the main system to trigger and 
 *            manage the recovery phase after an emergency.
 * @version   1.0.0
 * @date      3 August 2026
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
void RECOVERY_update();
// void RECOVERY_button_pressed();


#endif /* RECOVERY_INTERFACE_H */
