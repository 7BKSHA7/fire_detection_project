#ifndef NORMAL_INTERFACE_H_
#define NORMAL_INTERFACE_H_

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/COMMON_MACROS.h"

#include "../../../HAL/LED/LED_interface.h"
#include "../../../HAL/LED/LED_private.h"
#include "../../../HAL/BUZZER/BUZZER_interface.h"
#include "../../Safty_manager/Monitoring/Monitoring_Interface.h"

#include "NORMAL_config.h"
#include "NORMAL_private.h"

/* Shared fire-detection states.
 * This is the single source of truth for these state values.
 * warning / fire / emergency drivers must include THIS file
 * (not redefine these) to stay in sync:
 *
 *   #include "../NORMAL/NORMAL_interface.h"
 */
#define FIRE_STATE_NORMAL      0
#define FIRE_STATE_WARNING     1
#define FIRE_STATE_FIRE        2
#define FIRE_STATE_EMERGENCY   3

/* runs the normal-state behavior once, returns the state
 * the system should be in on the NEXT cycle.
 * stays FIRE_STATE_NORMAL as long as temp/smoke are within limits.
 */
u8 NORMAL_voidRun(void);

#endif /* NORMAL_INTERFACE_H_ */
