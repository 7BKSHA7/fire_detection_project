/**
* @file    Normal_Program.c
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
#include "../../../HAL/LED/LED_private.h"     // <-- needed for LED_STATE_NORMAL etc.
#include "../../../HAL/BUZZER/BUZZER_interface.h"
#include "../../Safty_manager/Monitoring/Monitoring_Interface.h"

#include "NORMAL_interface.h"
#include "NORMAL_config.h"
#include "NORMAL_private.h"

FIRE_STATE_t NORMAL_voidRun(void)
{
    // Green LED ON, everything else off
    LED_SetStatus(LED_STATE_NORMAL);

    // No alarm
    BUZZER_Off();

    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);

    if (NORMAL_CheckTransition(currentTemp, currentSmoke) == true)
    {
        return FIRE_STATE_WARNING;
    }

    return FIRE_STATE_NORMAL;
}

static u8 NORMAL_CheckTransition(u8 temp, u8 smoke)
{
    if ((temp > NORMAL_TEMP_THRESHOLD) || (smoke > NORMAL_SMOKE_THRESHOLD))
    {
        return true;
    }
    return false;
}
