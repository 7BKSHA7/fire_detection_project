/**
 * @file      Emergency_Interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface for the Emergency Fire State.
 * @details   This file contains the function prototypes and public APIs 
 *            for the Emergency state. Based on system requirements:
 *            - Triggered when Temp > 70 & Smoke > 200.
 *            - Actions: Red light blinks, Buzzer toggles, LCD shows warning.
 *            - Sensor readings stop until manual ACK is received.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef EMERGENCY_INTERFACE_H
#define EMERGENCY_INTERFACE_H

#include "../Normal/Normal_Interface.h"
#include "Emergency_Private.h"
#include "Emergency_Config.h"

/*
emergecny 
fire_temp > 70
smoke_temp > 200
red - light blinking
stop reading until ACK
warning lcd 
buzzer toggle
---------------------------
*/

FIRE_STATE_t EMERGENCY_voidRun(void);


#endif /* EMERGENCY_INTERFACE_H */
