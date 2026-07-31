#include "Safty_manager/System/System_Interface.h"
#include "Safty_manager/Monitoring/Monitoring_Interface.h"
#include "Safty_manager/EventLogger/EventLogger_Interface.h"
#include "Safty_manager/Recovery/Recovery_Interface.h"

#include "Fire_detection/Emergency/Emergency_Interface.h"
#include "Fire_detection/Fire/Fire_Interface.h"
#include "Fire_detection/Normal/Normal_Interface.h"
#include "Fire_detection/Warning/Warning_Interface.h"

void main ()
{
    SYSTEM_init();
    MONITROING_init();
    TIMER0_set_call_back_fucntion(Timer0_overflow_interput , MONITORING_update);
    while(1)
    {
        MONITORING_update();
        LCD_WriteNUMBER(MONITORING_get_values(temp_values) , Lcd_4bitMode);

    }
}