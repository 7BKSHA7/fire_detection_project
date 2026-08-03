/**
 * @file      EXTI_private.h
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the EXTI (External Interrupt) Driver.
 * @details   This file contains internal macros representing the microcontroller 
 *            register bits for external interrupts (MCUCR, MCUCSR, GICR, GIFR), 
 *            along with configuration constants used by the EXTI implementation.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define Exti_ISC11 3
#define Exti_ISC10 2 

#define Exti_ISC01 1 
#define Exti_ISC00 0 

#define Exti_ISC2  6 

#define Exti_INT1  7 
#define Exti_INT0  6 
#define Exti_INT2  5


#define Exti_INTF1  7 
#define Exti_INTF0  6
#define Exti_INTF2  5


#define Exti_LowLevel    4 
#define Exti_AnyChange   5
#define Exti_FallingEdge 6 
#define Exti_RisingEdge  7 


#define Exti_Interrupt0    3 
#define Exti_Interrupt1    4 
#define Exti_Interrupt2    5 

#endif 
