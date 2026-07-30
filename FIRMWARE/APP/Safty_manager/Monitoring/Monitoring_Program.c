/**
* @file    Monitoring_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "Monitoring_Interface.h"
#include "../System/System_Interface.h"


void MONITORING_update() // mointer the numbers of temp and smoke
{
    config.temprature = LM35_read_temp();
    config.smoke = MQ2_read_smoke();
}