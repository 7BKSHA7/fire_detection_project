/**
* @file    Emergency_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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

FIRE_STATE_t EMERGENCY_voidRun(void)
{
    LED_SetStatus(LED_STATE_EMERGENCY);  // red light blinking
    BUZZER_Toggle();
    LCD_WriteString("!!EMERGENCY!!" , Lcd_4bitMode);

    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);

    if (EMERGENCY_CheckTransition(currentTemp , currentSmoke) == true)
    {
        return FIRE_STATE_EMERGENCY;
    }
    return FIRE_STATE_NORMAL;
}

static u8 EMERGENCY_CheckTransition(u8 temp, u8 smoke)
{
    if (temp > EMERGENCY_TEMP_THRESHOLD && smoke > EMERGENCY_SMOKE_THRESHOLD)
    {
        return true;
    }
    return false;
}


