/**
* @file    Monitoring_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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

void MONITROING_init() // intialize the monitoring program to start the timer and enable global interrupt and write the first line of lcd
{
    TIMER0_init(config_timer);
    TIMER0_start(Timer0_Prescaler8);
    TIMER0_set_call_back_fucntion(Timer0_overflow_interput , MONITORING_update);
}


void MONITORING_update() // mointer the numbers of temp and smoke
{
    static u32 count = 0 ;
    count ++ ;

    if ((count % 2) == 0) // 100 / 50 --> every 100ms
    {
        temperature = LM35_get_temperature();
        smoke = MQ2_read_smoke();
    }
    if ((count % 5) == 0)  // 250 / 50  // every 250ms
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

    }
    if ((count % 20) == 0) // 1 sec
    {
        // uart update
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