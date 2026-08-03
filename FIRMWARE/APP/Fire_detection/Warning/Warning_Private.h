/**
* @file    Warning_Private.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "../../../Lib/STD_TYPES.h"
#ifndef WARNING_PRIVATE_H_
#define WARNING_PRIVATE_H_

/* returns true if values are back below warning range -> go to normal */
static u8 WARNING_CheckBackToNormal(u8 temp, u8 smoke);

/* returns true if values exceeded warning range -> escalate to fire */
static u8 WARNING_CheckEscalateToFire(u8 temp, u8 smoke);

#endif /* WARNING_PRIVATE_H_ */

