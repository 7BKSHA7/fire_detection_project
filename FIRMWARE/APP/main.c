#include "Safty_manager/System/System_Interface.h"
#include "Safty_manager/Monitoring/Monitoring_Interface.h"
#include "Safty_manager/EventLogger/EventLogger_Interface.h"
#include "Safty_manager/Recovery/Recovery_Interface.h"

#include "Fire_detection/Emergency/Emergency_Interface.h"
#include "Fire_detection/Fire/Fire_Interface.h"
#include "Fire_detection/Normal/Normal_Interface.h"
#include "Fire_detection/Warning/Warning_Interface.h"

#include <util/delay.h>

void main ()
{
    DIO_set_pin_direction(Dio_groupD , Dio_pin7 , output);
    SYSTEM_init();
    // MONITROING_init();
    // RECOVERY_init();
    // MONITORING_update();
    // RECOVERY_update();
    // while(1)
    // {

    // }
}