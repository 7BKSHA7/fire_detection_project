/**
* @file    Button_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../MCAL/REG_MAP.h"

#include "BUTTON_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

void BUTTON_init(void)
{
    DIO_set_pin_direction(BUTTON_PORT, BUTTON_PIN, input);
    DIO_set_pin_value(BUTTON_PORT, BUTTON_PIN, high); 
}

u8 BUTTON_GetState(void)
{
    u8 pinLevel = DIO_get_pin_value(BUTTON_PORT, BUTTON_PIN);

    if (pinLevel == low) 
    {
        return BUTTON_PRESSED;
    }
    else
    {
        return BUTTON_RELEASED;
    }
}

