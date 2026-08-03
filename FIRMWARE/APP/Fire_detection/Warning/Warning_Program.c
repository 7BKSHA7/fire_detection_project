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

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/COMMON_MACROS.h"

#include "../../../HAL/LED/LED_interface.h"
#include "../../../HAL/LED/LED_private.h"
#include "../../../HAL/BUZZER/BUZZER_interface.h"
#include "../../../HAL/LCD/LCD_interface.h"
#include "../../Safty_manager/Monitoring/Monitoring_Interface.h"

#include "../NORMAL/NORMAL_Config.h"
#include "../NORMAL/NORMAL_Interface.h"

#include "WARNING_interface.h"
#include "WARNING_config.h"
#include "WARNING_private.h"

u8 WARNING_voidRun(void)
{
    // Yellow LED ON, everything else off
    LED_SetStatus(LED_STATE_WARNING);

    // No alarm yet, just a visual/text warning
    BUZZER_Off();

    // show "Warning" on LCD, row 0, starting at column 0
    LCD_GoToXY(Row1_Pos1, 0, Lcd_4bitMode);
    LCD_WriteString((u8*)"Warning", Lcd_4bitMode);

    // continue monitoring
    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);

    if (WARNING_CheckEscalateToFire(currentTemp, currentSmoke) == true)
    {
        return FIRE_STATE_FIRE;
    }

    if (WARNING_CheckBackToNormal(currentTemp, currentSmoke) == true)
    {
        return FIRE_STATE_NORMAL;
    }

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

static u8 WARNING_CheckBackToNormal(u8 temp, u8 smoke)
{
    if ((temp < NORMAL_TEMP_THRESHOLD) && (smoke < NORMAL_SMOKE_THRESHOLD))
    {
        return true;
    }
    return false;
}
