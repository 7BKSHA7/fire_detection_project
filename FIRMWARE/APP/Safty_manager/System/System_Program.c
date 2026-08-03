/**
 * @file      System_Program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the core System application layer.
 * @details   This file contains the initialization and the main update loop logic 
 *            for the Fire Alarm System. It orchestrates all HAL components (LCD, 
 *            Sensors, LEDs, Buzzer) and manages the system states (Monitoring, 
 *            Event Logging, and Recovery).
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "System_Interface.h"
#include "../Monitoring/Monitoring_Interface.h"
#include "../EventLogger/EventLogger_Interface.h"
#include "../Recovery/Recovery_Interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

static u8 system_state = FIRE_STATE_NORMAL ;
// intilazit the system to start all HAL drivers in the program so everything starts working
void SYSTEM_init () 
{

    LED_initialization(); // turn on the dio pins for all 3 leds
    LCD_INIT(Lcd_4bitMode); // star the lcd in 4bit mode 
    MQ2_init(); // start the smoke dectector
    LM35_init(); // start the flame detetor
    BUTTON_init(); // start the button to read inputs
    BUZZER_init(); // start the buzzer to alarm the user
    // EXTI_Init(Exti_Interrupt0, Exti_FallingEdge);
    // EXTI_Enable(Exti_Interrupt0);
    // EXTI_set_call_back(RECOVERY_button_pressed); // not like this used 

    EVENTLOGGER_init();

    MONITROING_init();

    LCD_WriteString("SYS:init done" , Lcd_4bitMode);
    _delay_ms(2000);
    LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_4bitMode);

    LCD_WriteString("temp  : " , Lcd_4bitMode);
    LCD_GoToXY(Lcd_line1 , Lcd_column0 , Lcd_4bitMode);
    LCD_WriteString("smoke : " , Lcd_4bitMode);

    
    
    GIE_Enable(); // enable the global interrupt to allow the EXTI to work
    
}
// update the system reading each time it runs in the while 1
u8 SYSTEM_update()
{
    // system_state = NORMAL_voidRun();
    // return SYSTEM_switch_helper(system_state);
}

// u8 SYSTEM_switch_helper (u8 data)
// {
//     switch(data)
//     {        
//         case FIRE_STATE_NORMAL :
//             return FIRE_STATE_NORMAL;
//             break;
//         case FIRE_STATE_WARNING :
//             return FIRE_STATE_WARNING;
//             break;
//         case FIRE_STATE_FIRE :
//             return FIRE_STATE_FIRE;
//             break;
//         case FIRE_STATE_EMERGENCY :
//             return FIRE_STATE_EMERGENCY;
//             break;
//         default: 
//             return FIRE_STATE_NORMAL;
//             break;
//     }
// }