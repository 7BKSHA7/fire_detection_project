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

    // config_system_values.temprature  = 0 ;
    // config_system_values.acknowledged = NOT_ACK;
    // config_system_values.smoke = 0;
    // config_system_values.current_state = NORMAL;
    // config_system_values.prev_state = NORMAL;
    
    LCD_WriteString("SYS:init done" , Lcd_4bitMode);
    _delay_ms(2000);
    LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_4bitMode);
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
