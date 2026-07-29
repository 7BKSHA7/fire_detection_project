#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void TIMER0_init(u8 Timer_mode);
void TIMER0_start(u8 clock_select_value);
void TIMER0_stop(void);

void TIMER0_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void));


// compare match
void __vector_10(void)   __attribute__((signal));
// overflow 
void __vector_11(void)   __attribute__((signal));

#endif