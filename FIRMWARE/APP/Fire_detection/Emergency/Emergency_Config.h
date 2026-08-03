/**
* @file    Emergency_Config.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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
