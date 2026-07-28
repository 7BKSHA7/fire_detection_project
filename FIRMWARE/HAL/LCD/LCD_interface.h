#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void LCD_INIT        (u8 ModeType);
void LCD_WriteCommand(u8 command , u8 ModeType);
void LCD_WriteData   (u8 data , u8 ModeType);
void LCD_WriteString (u8*str , u8 ModeType);
void LCD_GoToXY      (u8 row , u8 column, u8 ModeType);
void LCD_WriteNUMBER (u8 Number, u8 ModeType);

#endif