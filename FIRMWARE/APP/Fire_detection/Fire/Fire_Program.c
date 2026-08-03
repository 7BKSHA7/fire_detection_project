/**
 * @file      Fire_Program.c
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Fire State.
 * @details   This file handles the critical Fire state logic. It turns on the 
 *            red LED, activates the buzzer, and displays "FIRE ALARM" on the LCD. 
 *            It continuously monitors sensors to escalate to EMERGENCY or 
 *            de-escalate back to WARNING.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Fire_Interface.h"

u8 FIRE_voidRun(void)
{
    
    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);
    
    if (FIRE_CheckTransition(currentTemp, currentSmoke) == true)
    {
        return EMERGENCY_voidRun();
        // return FIRE_STATE_FIRE;
    }
    
    EVENTLOGGER_fire();
    LED_SetStatus(LED_STATE_NOTICE_FIRE);    
    // No alarm
    BUZZER_On();
    return FIRE_STATE_WARNING;

}
// WARNING_TEMP_THRESHOLD
static u8 FIRE_CheckTransition(u8 temp, u8 smoke)
{
    if ((temp >= FIRE_TEMP_THRESHOLD) || (smoke >= FIRE_SMOKE_THRESHOLD))
    {
        return true;   // yes, limit reached -> time to leave normal
    }
    return false;      // no, still safe -> stay normal

}
