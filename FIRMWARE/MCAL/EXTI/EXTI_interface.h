#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
#include "../REG_MAP.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*  
 * @fn       EXTI_Init
 * @brief    Select the Configuration of Sens contorl for the Specific Interrupt 
 * @details
 * @param InterruptName  this Parameter can on of this following option
 *  (Exti_Interrupt0,Exti_Interrupt1,Exti_Interrupt2)
 * @param SensConfig 
 */

void EXTI_Init(u8 InterruptName,u8 SensConfig);
void EXTI_Enable(u8 InterruptName);
void EXTI_Disable(u8 InterruptName);




#endif 
