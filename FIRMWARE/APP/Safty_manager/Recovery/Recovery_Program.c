/**
* @file    Recovery_Program.c
* @author beshoy
* @author beshoy
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "Recovery_Interface.h"


// must be done after button and fire

static volatile u8 Recovery_request = false ;

void RECOVERY_button_pressed() // action to do 
{
    // Recovery_request = BUTTON_GetState();
    BUZZER_On(); 
}

void RECOVERY_init() // init the recovery after emgerecny so we can ACK that the system is ok
{
    // enable the EXTI so it can register

    // the call back fuction
    // enable global interput
}

u8 RECOVERY_update()
{
    if (Recovery_request == true)
    {
        Recovery_request = false ; // to tell the system that the user ack it
        return true ;
    }
    return false ;
}
