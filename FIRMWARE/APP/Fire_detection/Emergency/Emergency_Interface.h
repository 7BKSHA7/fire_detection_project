/**
* @file    Emergency_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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
