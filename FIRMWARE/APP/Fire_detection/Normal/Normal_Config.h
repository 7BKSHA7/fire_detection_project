/**
 * @file      Normal_Config.h
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the Normal Fire State.
 * @details   This file contains user-configurable parameters and thresholds 
 *            specific to the Normal state logic. It defines the limits at 
 *            which the system transitions from Normal to Warning.
 *            
 *            System States Overview:
 *            - NORMAL:    Temp < 45, Smoke < 70 (Green light, continue reading)
 *            - WARNING:   45 <= Temp < 60, 70 <= Smoke < 130 (Yellow light, Warning LCD)
 *            - FIRE:      60 <= Temp < 70, 130 <= Smoke < 200 (Red light, Fire LCD, Buzzer ON)
 *            - EMERGENCY: Temp >= 70, Smoke >= 200 (Red light blink, Emergency LCD, Buzzer toggle, Stop reading until ACK)
 * 
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

/*
fire_temp < 45
smoke_temp < 70
green - light 
contiune reading
----------------------------
waring
fire_temp > 45 && < 60 
smoke_temp > 70 &&  < 130
yellow - light 
contiue reading no lcd write
lcd - waring
----------------------------
fire
fire_temp > 60 && < 70 
smoke_temp > 130 &&  < 200
contiue reading no lcd write
red - light
lcd - fire alarm 
buzzer on 
---------------------------
emergecny 
fire_temp > 70
smoke_temp > 200
red - light blinking
stop reading until ACK
warning lcd 
buzzer toggle
---------------------------

*/
#ifndef NORMAL_CONFIG_H
#define NORMAL_CONFIG_H


#include "../../../LIB/STD_TYPES.h"

/* Thresholds that decide when we must LEAVE the normal state
 * and hand control to the warning state.
 * Tune these to your MQ2 / LM35 calibration.
 */
#define NORMAL_TEMP_THRESHOLD      45   // degrees C, above this -> warning
#define NORMAL_SMOKE_THRESHOLD     70   // smoke reading, above this -> warning


#endif /* NORMAL_CONFIG_H */
