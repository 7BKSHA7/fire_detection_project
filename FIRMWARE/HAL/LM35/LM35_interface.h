#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void LM35_init(void);
u8 LM35_get_temperature(void);

#endif
