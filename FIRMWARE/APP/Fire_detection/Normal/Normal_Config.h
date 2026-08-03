/**
* @file    Normal_Config.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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
