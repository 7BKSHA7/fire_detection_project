#ifndef WARNING_INTERFACE_H_
#define WARNING_INTERFACE_H_

#include "../NORMAL/NORMAL_interface.h"   // shared FIRE_STATE_* defines
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/COMMON_MACROS.h"

#include "../../../HAL/LED/LED_interface.h"
#include "../../../HAL/LED/LED_private.h"
#include "../../../HAL/BUZZER/BUZZER_interface.h"
#include "../../../HAL/LCD/LCD_interface.h"
#include "../../Safty_manager/Monitoring/Monitoring_Interface.h"
#include "WARNING_config.h"
#include "WARNING_private.h"
/* runs the warning-state behavior once, returns the state
 * the system should be in on the NEXT cycle
 */
u8 WARNING_voidRun(void);

#endif /* WARNING_INTERFACE_H_ */
