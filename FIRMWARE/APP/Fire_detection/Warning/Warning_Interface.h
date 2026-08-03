/**
 * @file      Warning_Interface.h
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface for the Warning Fire State.
 * @details   This file contains the function prototypes and public APIs 
 *            for the Warning state. It includes the Normal interface to 
 *            share the global FIRE_STATE_t enumeration.
 * @version   1.0.0
 * @date      3 August 2026
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
