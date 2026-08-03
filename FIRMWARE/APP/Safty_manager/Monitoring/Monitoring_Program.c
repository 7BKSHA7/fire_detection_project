/**
 * @file      Monitoring_Program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Monitoring subsystem.
 * @details   This file contains a timer-based scheduler that periodically reads 
 *            the temperature and smoke sensors, updates the LCD, and handles 
 *            the state transitions into emergencies.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#include "Monitoring_Interface.h"

timer0_config_t config_timer =  // timer configuration to start the timer in normal mode with prescaler 8 and preload value 100
{
    .timer_mode = Timer0_normalmode,
    .preload_value = timer_preload_value,
};

static u8 temperature = 0 ;
static u8 smoke = 0;
static u8 current_state = FIRE_STATE_NORMAL ; // to know if the system is in emergency or not to stop the monitoring when in emergency
static u8 button_state = BUTTON_RELEASED ; // to know if the button is pressed or not to stop the monitoring when in emergency

void MONITROING_init() // intialize the monitoring program to start the timer and enable global interrupt and write the first line of lcd
{
    TIMER0_init(config_timer);
    TIMER0_start(Timer0_Prescaler8);
    TIMER0_set_call_back_fucntion(Timer0_overflow_interput , MONITORING_update);
}

/*
4 fucntions
read temps 
read smoke 
if temp || smoke < values 
    -> next level
if false
    -> stay level
normal
warning
fire
emgergecny
*/
// timer 
void MONITORING_update() // mointer the numbers of temp and smoke // schudeler insted of just mointering
{
    static u32 count = 0 ;
    count ++ ;
    // check
    // lo true count reminder 
    // update counter if 
    // if the button is not pressed and the system is not in emergency then
    // the system contiues to read the values and update lcd
    // but if its emergecny then we say recovery and ask for button to be pressed
    
    if ((count % 2) == 0) // read the button value every 50ms 
    {
        button_state = BUTTON_GetState();
    }
    if (current_state == FIRE_STATE_EMERGENCY)
    {
        // EVENTLOGGER_emergency();
        // RECOVERY_init();
        if (button_state == BUTTON_PRESSED)
        {
            EVENTLOGGER_acknowledged();
            current_state = FIRE_STATE_NORMAL; // to tell the system that the user ack it
            RECOVERY_update();
            EVENTLOGGER_reset();
        }
    }
    else 
    {
        if ((count % 2) == 0) // 100 / 50 --> every 100ms
        {
            temperature = LM35_get_temperature();
            smoke = MQ2_read_smoke();
        }
        if ((count % 5) == 0 && (current_state != FIRE_STATE_EMERGENCY))  // 250 / 50  // every 250ms
        {
            LCD_GoToXY(Lcd_line0 , Lcd_column8 , Lcd_4bitMode);
            LCD_WriteString("        " , Lcd_4bitMode);
            LCD_GoToXY(Lcd_line0 , Lcd_column8 , Lcd_4bitMode);
            LCD_WriteNUMBER(temperature , Lcd_4bitMode);
            
            LCD_GoToXY(Lcd_line1 , Lcd_column8 , Lcd_4bitMode);
            
            LCD_WriteString("        " , Lcd_4bitMode);
            LCD_GoToXY(Lcd_line1 , Lcd_column8 , Lcd_4bitMode);
            LCD_WriteNUMBER(smoke , Lcd_4bitMode);
            LCD_WriteString("        " , Lcd_4bitMode);
            // read 
        }
    }
    if ((count % 20) == 0) // 1 sec
    {
        current_state = NORMAL_voidRun();
        // uart update
        EVENTLOGGER_normal();
        TIMER0_set_preload(timer_preload_value);
        count = 0 ;    
    }
    
}

u8 MONITORING_get_values(u8 type)  // send the values of temp and smoke to system 
{
    if (type == temp_values)
    {
        return temperature;
    }
    else if (type == smoke_values)
    {
        return smoke;
    }
}
