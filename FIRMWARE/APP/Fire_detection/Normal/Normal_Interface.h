/**
* @file    Normal_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef NORMAL_INTERFACE_H
#define NORMAL_INTERFACE_H

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/COMMON_MACROS.h"

#include "../../../HAL/LED/LED_interface.h"
#include "../../../HAL/LCD/LCD_interface.h"
#include "../../../HAL/LED/LED_private.h"     // <-- needed for LED_STATE_NORMAL etc.
#include "../../../HAL/BUZZER/BUZZER_interface.h"
#include "../../Safty_manager/Monitoring/Monitoring_Interface.h"

#include "../../../LIB/STD_TYPES.h"
#include "NORMAL_config.h"
#include "NORMAL_private.h"


/* Shared fire-detection states.
 * This is the single source of truth for FIRE_STATE_t.
 * warning / fire / emergency drivers must include THIS file
 * (not redefine the enum) to stay in sync:
 *
 *   #include "../NORMAL/NORMAL_interface.h"
 */
typedef enum
{
    FIRE_STATE_NORMAL = 0,
    FIRE_STATE_WARNING,
    FIRE_STATE_FIRE,
    FIRE_STATE_EMERGENCY
} FIRE_STATE_t;

/* runs the normal-state behavior once, returns the state
 * the system should be in on the NEXT cycle.
 * stays FIRE_STATE_NORMAL as long as temp/smoke are within limits.
 */
FIRE_STATE_t NORMAL_voidRun(void);

#endif /* NORMAL_INTERFACE_H */
