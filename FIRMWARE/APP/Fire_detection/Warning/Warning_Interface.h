/**
* @file    Warning_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef WARNING_INTERFACE_H_
#define WARNING_INTERFACE_H_

#include "../NORMAL/NORMAL_interface.h"   // FIRE_STATE_t shared definition

/* runs the warning-state behavior once, returns the state
 * the system should be in on the NEXT cycle
 */
FIRE_STATE_t WARNING_voidRun(void);

#endif /* WARNING_INTERFACE_H_ */
