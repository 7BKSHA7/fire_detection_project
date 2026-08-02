/**
* @file    System_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#include "System_Interface.h"
#include "../Monitoring/Monitoring_Interface.h"
#include "../EventLogger/EventLogger_Interface.h"
#include "../Recovery/Recovery_Interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

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
void SYSTEM_update()
{
    // start to mointer
    // chnage state 
    // fire state
    // log 
    // recovr from state
    
}
