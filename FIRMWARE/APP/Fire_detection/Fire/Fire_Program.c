/**
* @file    Fire_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "Fire_Interface.h"
FIRE_STATE_t FIRE_voidRun(void)
{
    LED_SetStatus(LED_STATE_NOTICE_FIRE);

    // No alarm
    BUZZER_On();

    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);

    if (FIRE_CheckTransition(currentTemp, currentSmoke) == true)
    {
        return FIRE_STATE_FIRE;
    }

    return FIRE_STATE_WARNING;

}

static u8 FIRE_CheckTransition(u8 temp, u8 smoke)
{
    if ((temp > WARNING_TEMP_THRESHOLD && temp <= FIRE_TEMP_THRESHOLD) || (smoke > WARNING_TEMP_THRESHOLD && smoke <= FIRE_SMOKE_THRESHOLD))
    {
        return true;   // yes, limit reached -> time to leave normal
    }
    return false;      // no, still safe -> stay normal

}
