#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#define Lcd_4bitMode     0
#define Lcd_8bitMode     1

#define Row1_Pos1 0x00
#define Row2_Pos1 0x40

#define LCD_CLEAR_DISPLAY        0x01 //clear all lcd and back to first position

#define LCD_RETURN_HOME          0x02 //make the cursor back to first position but with out delete anything

#define LCD_ENTRY_MODE           0x06 //Sets the cursor movement direction after typing:
                                      //0x06 cursor move to right___0x04 cursor move to left

#define LCD_DISPLAY_ON           0x0C //dispaly on and cursor off

#define LCD_OnlyCursor_ON        0x0E //dispaly on+ cursor on

#define LCD_DISPLAY_OFF          0x08 //display off+cursor off

#define LCD_DISPLAY_ON_BLINK     0x0F //dispaly on+ cursor on+ cursor blinking

#define LCD_MODETYBE_4BIT        0x28 

#define LCD_MODETYBE_8BIT        0x38

#define LCD_CURSOR_LEFT          0x10 //cursor move 1 position to left

#define LCD_CURSOR_RIGHT         0x14 //cursor move 1 position to right

#define LCD_SHIFT_LEFT           0x18 //move all screen to left

#define LCD_SHIFT_RIGHT          0x1C //move all screen to left

#endif