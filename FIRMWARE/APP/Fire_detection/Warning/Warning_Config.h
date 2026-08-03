/**
 * @file      Warning_Config.h
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the Warning Fire State.
 * @details   This file contains user-configurable thresholds specific to 
 *            the Warning state logic, defining the lower and upper limits 
 *            for temperature and smoke to handle escalation and de-escalation.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef WARNING_CONFIG_H_
#define WARNING_CONFIG_H_

#include "../../../Lib/STD_TYPES.h"

/* Warning state range: 60 > temp >= 45  OR  170 > smoke >= 70 */
#define WARNING_TEMP_LOW        45   // >= this enters/stays in warning
#define WARNING_TEMP_HIGH       60   // >= this escalates to fire

#define WARNING_SMOKE_LOW       70   // >= this enters/stays in warning
#define WARNING_SMOKE_HIGH      170  // >= this escalates to fire

#endif /* WARNING_CONFIG_H_ */

