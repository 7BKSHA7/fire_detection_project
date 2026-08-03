/**
 * @file      Emergency_Config.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the Emergency Fire State.
 * @details   This file contains user-configurable parameters and thresholds 
 *            specific to the Emergency state logic, such as temperature and 
 *            smoke limits.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef EMERGENCY_CONFIG_H
#define EMERGENCY_CONFIG_H

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

#define EMERGENCY_TEMP_THRESHOLD      70   // degrees C, above this -> warning
#define EMERGENCY_SMOKE_THRESHOLD     200   // smoke reading, above this -> warning


#endif /* EMERGENCY_CONFIG_H */
