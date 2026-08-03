
#include "NORMAL_interface.h"
u8 NORMAL_voidRun(void)
{
    u8 currentTemp  = MONITORING_get_values(temp_values);
    u8 currentSmoke = MONITORING_get_values(smoke_values);
    
    if (NORMAL_CheckTransition(currentTemp, currentSmoke) == true) // go to next level
    {
        return WARNING_voidRun();
        // return FIRE_STATE_WARNING;
    }
    
    // Green LED ON, everything else off
    LED_SetStatus(LED_STATE_NORMAL);
    
    // No alarm
    BUZZER_Off();
    return FIRE_STATE_NORMAL;
}

static u8 NORMAL_CheckTransition(u8 temp, u8 smoke)
{
    if ((temp >= NORMAL_TEMP_THRESHOLD) || (smoke >= NORMAL_SMOKE_THRESHOLD))
    {
        return true;
    }
    return false;
}
