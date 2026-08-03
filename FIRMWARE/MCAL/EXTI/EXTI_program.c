/**
 * @file      EXTI_program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the EXTI (External Interrupt) Driver.
 * @details   This file contains the configuration and control functions for 
 *            the External Interrupts (INT0, INT1, INT2). It handles sense 
 *            control setup, enabling/disabling interrupts, and managing ISR 
 *            callbacks to upper application layers.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#include "EXTI_interface.h"
static void (*INT0_call_back)(void) =Null;

void EXTI_Init(u8 InterruptName,u8 SensConfig)
{
    if(InterruptName==Exti_Interrupt0)
    {
        if(SensConfig==Exti_LowLevel)
        {
            ClearBit(MCUCR , Exti_ISC00);
            ClearBit(MCUCR , Exti_ISC01);
        }
        else if (SensConfig==Exti_AnyChange)
        {
            SetBit(MCUCR , Exti_ISC00);
            ClearBit(MCUCR , Exti_ISC01);   
        }
        else if (SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCR , Exti_ISC00);
            SetBit(MCUCR , Exti_ISC01);   
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCR , Exti_ISC00);
            SetBit(MCUCR , Exti_ISC01);
        }
    }
    else if (InterruptName==Exti_Interrupt1)
    {
        if(SensConfig==Exti_LowLevel)
        {
            ClearBit(MCUCR , Exti_ISC10);
            ClearBit(MCUCR , Exti_ISC11);
        }
        else if (SensConfig==Exti_AnyChange)
        {
            SetBit(MCUCR , Exti_ISC10);
            ClearBit(MCUCR , Exti_ISC11);
        }
        else if (SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCR , Exti_ISC10);
            SetBit(MCUCR , Exti_ISC11);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCR , Exti_ISC10);
            SetBit(MCUCR , Exti_ISC11);
        }
    }
    else if (InterruptName==Exti_Interrupt2)
    {
        if(SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCSR,Exti_ISC2);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCSR,Exti_ISC2);
        }
    }
}

void EXTI_Enable(u8 InterruptName)
{
    if(InterruptName==Exti_Interrupt0)
    {
        SetBit(GICR , Exti_INT0);
    }
    else if(InterruptName==Exti_Interrupt1)
    {
        SetBit(GICR , Exti_INT1);
    }
    else if(InterruptName==Exti_Interrupt2)
    {
        SetBit(GICR , Exti_INT2);
    }
}


void EXTI_Disable(u8 InterruptName)
{
    if(InterruptName==Exti_Interrupt0)
    {
        ClearBit(GICR , Exti_INT0);
    }
      else if(InterruptName==Exti_Interrupt1)
    {
        ClearBit(GICR , Exti_INT1);
    }
    else if(InterruptName==Exti_Interrupt2)
    {
        ClearBit(GICR , Exti_INT2);
    }
}

void EXTI_set_call_back (void (*PF)(void))
{
    if ( PF != Null)
    {
        INT0_call_back = PF;
    }
}

void __vector_1(void)  __attribute__((signal,used));
void __vector_1(void)
{
    if (INT0_call_back != Null)
    {
        INT0_call_back();
    }
}
