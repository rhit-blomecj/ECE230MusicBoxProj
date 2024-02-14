/*
 * LCDDriver.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "LCDDriver.h"

//TODO LCDconfig(#LCDPort)

//TODO LCDinit(#LCDPort) this should run the initialization commands I didn't get 4 bit to work so we are just doing an 8 bit driver unfortunately
void lcd8bits_init(void)
{
    LCD_CONTROL_PORT->DIR = LCD_CONTROL_PORT->DIR | ((0x01<<LCD_RS) | (0x01<<LCD_EN));
    LCD_CONTROL_PORT->SEL0 = LCD_CONTROL_PORT->SEL0 & (~(0x01<<LCD_RS) | ~(0x01<<LCD_EN));
    LCD_CONTROL_PORT->SEL1 = LCD_CONTROL_PORT->SEL1 & (~(0x01<<LCD_RS) | ~(0x01<<LCD_EN));
    LCD_DATA->DIR = 0b11111111;
    LCD_DATA->SEL0 = 0b00000000;
    LCD_DATA->SEL1 = 0b00000000;

    Set_Command_Mode

    Set_Enable_Low

    DelayMs(20); // wait 15mSec after power applied,
    lcd8bits_write(CMD_MODE, LCDCMD_FunctionSet); // function set: 8-bit mode, 2 lines, 5x7 dots
    DelayMs(4);
    lcd8bits_write(CMD_MODE, LCDCMD_DisplaySettings); // display ON/OFF control: display on, cursor off, blink off
    DelayMs(4);
    lcd_clear(); // Clear screen
    DelayMs(4);
    lcd8bits_write(CMD_MODE, LCDCMD_EMS); // Set entry Mode
} //end lcd8bits_init()



//TODO LCDWrite (#LCDPort, char (just a one byte number), INSTR or DATA modes)

//TODO PrintChar(#LCDPort, char); calls LCDWrite with this and DATA mode

//TODO PrintString(#LCDPort, char *); iterate through chars calling Print Char allow a certain delay between chars
//  TODO also enable LCD scrolling if song name or artist name will run off the display (check if the string being sent to LCD will run out of space (maybe make main in charge of this with an interupt handler and make a function that shifts the LCD)

//TODO Add fucntions that manipulate address to change line and position on screen when we want or just display things where we want them


