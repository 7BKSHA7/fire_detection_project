/**
* @file    Warning_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/



#include "Warning_Interface.h"


u8 WARNING_voidRun(void)
{
    
    // // show "Warning" on LCD, row 0, starting at column 0
    // LCD_GoToXY(Row1_Pos1, 0, Lcd_4bitMode);
    // LCD_WriteString((u8*)"Warning", Lcd_4bitMode);
    
    // continue monitoring
    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);
    
    if (WARNING_CheckEscalateToFire(currentTemp, currentSmoke) == true)
    {
        return FIRE_voidRun();
        // return FIRE_STATE_FIRE;
    }
    
    // Yellow LED ON, everything else off
    LED_SetStatus(LED_STATE_WARNING);

    // No alarm yet, just a visual/text warning
    BUZZER_Off();
    // if (WARNING_CheckBackToNormal(currentTemp, currentSmoke) == true)
    // {
    //     return FIRE_STATE_NORMAL;
    // }

    return FIRE_STATE_WARNING;
}

static u8 WARNING_CheckEscalateToFire(u8 temp, u8 smoke)
{
   if ((temp >= WARNING_TEMP_THRESHOLD) || (smoke >= WARNING_SMOKE_THRESHOLD))
    {
        return true;
    }
    return false;
}

// static u8 WARNING_CheckBackToNormal(u8 temp, u8 smoke)
// {
//     if ((temp < NORMAL_TEMP_THRESHOLD) && (smoke < NORMAL_SMOKE_THRESHOLD))
//     {
//         return true;
//     }
//     return false;
// }
