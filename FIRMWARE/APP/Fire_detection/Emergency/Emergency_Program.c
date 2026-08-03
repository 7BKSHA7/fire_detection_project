/**
 * @file      Emergency_Program.c
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Emergency Fire State.
 * @details   This file handles the logic for the most critical state of the system,
 *            triggering alarms, blinking LEDs, and locking the system until manually 
 *            acknowledged by the user.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include "Emergency_Interface.h"

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
u8 EMERGENCY_voidRun(void)
{
    LED_SetStatus(LED_STATE_EMERGENCY);  // red light blinking
    BUZZER_Toggle();
    LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_4bitMode);
    LCD_WriteString((u8*)"!!EMERGENCY!!", Lcd_4bitMode);
    
    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);
    
    if (EMERGENCY_CheckTransition(currentTemp, currentSmoke) == true)
    {
        return FIRE_STATE_EMERGENCY;
    }
    // return FIRE_STATE_NORMAL;
}

static u8 EMERGENCY_CheckTransition(u8 temp, u8 smoke)
{
    if (temp > EMERGENCY_TEMP_THRESHOLD || smoke > EMERGENCY_SMOKE_THRESHOLD)
    {
        return true;
    }
    return false;
}

