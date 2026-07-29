#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_

// wavegenration 
#define Timer0_FOC0     7
#define Timer0_WGM00    6
#define Timer0_WGM01    3

//output mode
#define Timer0_COM01    5
#define Timer0_COM00    4

//clock select 
#define Timer0_CS02     2
#define Timer0_CS01     1
#define Timer0_CS00     0

// choose mode 
#define Timer0_normalmode 0 
#define Timer0_CTCmode    1

// choose comapre 
#define Timer0_OC0disconnect 0
#define Timer0_OC0toggle     1
#define Timer0_OC0clear      2
#define Timer0_OC0set        3

// to choose the prescaller
#define Timer0_Disable        0
#define Timer0_Prescaler1     1
#define Timer0_Prescaler8     2
#define Timer0_Prescaler64    3
#define Timer0_Prescaler256   4
#define Timer0_Prescaler1024  5

// choose the type 
#define Timer0_extrenalfalling 6
#define Timer0_extrenalrising  7

#define clock_select_mask  0x07

// interput enable
#define Timer0_OCIE0    1
#define Timer0_TOIE0     0

#define Timer0_overflow_interput 0 
#define Timer0_compare_match_interput 1


#endif