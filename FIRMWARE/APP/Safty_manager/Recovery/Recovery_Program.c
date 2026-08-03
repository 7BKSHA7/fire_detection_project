/**
 * @file      Recovery_Program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Recovery subsystem.
 * @details   This file contains the logic for system recovery after an emergency 
 *            or fire alarm state. It prompts the user to acknowledge the emergency 
 *            and restores the normal monitoring UI upon recovery.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Recovery_Interface.h"


// must be done after button and fire

void RECOVERY_init() // init the recovery after emgerecny so we can ACK that the system is ok
{
    LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_4bitMode);
    LCD_WriteString("EMERGENCY" , Lcd_4bitMode);
    LCD_GoToXY(Lcd_line1 , Lcd_column0 , Lcd_4bitMode);
    LCD_WriteString("press the button" , Lcd_4bitMode);
}

void RECOVERY_update()
{
    LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_4bitMode);
    LCD_WriteString("temp  : " , Lcd_4bitMode);
    LCD_GoToXY(Lcd_line1 , Lcd_column0 , Lcd_4bitMode);
    LCD_WriteString("smoke : " , Lcd_4bitMode);
}
