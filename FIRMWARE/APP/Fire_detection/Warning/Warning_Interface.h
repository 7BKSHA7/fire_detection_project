#ifndef WARNING_INTERFACE_H_
#define WARNING_INTERFACE_H_

#include "../NORMAL/NORMAL_interface.h"   // shared FIRE_STATE_* defines

/* runs the warning-state behavior once, returns the state
 * the system should be in on the NEXT cycle
 */
u8 WARNING_voidRun(void);

#endif /* WARNING_INTERFACE_H_ */
