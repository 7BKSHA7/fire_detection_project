#include "TIMER_interface.h"

static void (*timer0_OVFcallback)(void) = Null;
static void (*timer0_CTCcallback)(void) = Null;

void TIMER0_init(u8 Timer_mode)
{
    if (Timer_mode == Timer0_normalmode)
    {
        // set normal mode in tccr0 and enable interput
        ClearBit(TCCR0 , Timer0_WGM00);
        ClearBit(TCCR0 , Timer0_WGM01);
        // enable interput 
        SetBit(TIMSK, Timer0_TOIE0);
    }
    else if (Timer_mode == Timer0_CTCmode)
    {
        // set ctc mode in tccr0 and enable interput 
        ClearBit(TCCR0 , Timer0_WGM00);
        SetBit(TCCR0 , Timer0_WGM01);
        // enable interput
        SetBit(TIMSK, Timer0_OCIE0);

    }
}
void TIMER0_start(u8 clock_select_value)
{
    // select prescaller
    if (clock_select_value != Timer0_Disable)
    {
        TCCR0 = (TCCR0 &~ clock_select_mask) | clock_select_value ;
    }
}
void TIMER0_stop(void)
{
    TCCR0 = (TCCR0 &~ clock_select_mask) | Timer0_Disable ;
}

void TIMER0_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void))
{
    if (timer_interupt_type == Timer0_overflow_interput)
    {
        if (PF != Null)
        {
            timer0_OVFcallback = PF;
        }
    }
    else if (timer_interupt_type == Timer0_compare_match_interput)
    {
        if (PF != Null)
        {
            timer0_CTCcallback = PF;
        }
    }
}


// compare match
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
    timer0_CTCcallback();
}
// overflow 
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
    timer0_OVFcallback();
}
