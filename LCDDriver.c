/*
 * LCDDriver.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "LCDDriver.h"

#define Set_Command_Mode LCDControlPort->OUT = (LCDControlPort->OUT) & (~(LCDRSPin));
#define Set_Data_Mode LCDControlPort->OUT = (LCDControlPort->OUT) | (LCDRSPin);

#define Set_Enable_Low  LCDControlPort->OUT =  (LCDControlPort->OUT) & ~(LCDEPin);
#define Set_Enable_High  LCDControlPort->OUT =  (LCDControlPort->OUT) | (LCDEPin);
//TODO LCDconfig(#LCDPort)

//TODO LCDinit(#LCDPort) this should run the initialization commands I didn't get 4 bit to work so we are just doing an 8 bit driver unfortunately
void lcd8bits_init(void)
{
    LCDControlPort->DIR = LCDControlPort->DIR | ((LCDRSPin) | (LCDEPin));
    LCDControlPort->SEL0 = LCDControlPort->SEL0 & (~(LCDRSPin) | ~(LCDEPin));
    LCDControlPort->SEL1 = LCDControlPort->SEL1 & (~(LCDRSPin) | ~(LCDEPin));
    LCDDataPort->DIR = 0b11111111;
    LCDDataPort->SEL0 = 0b00000000;
    LCDDataPort->SEL1 = 0b00000000;

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

void LCD_STROBE(void) {
    Set_Enable_High
    DelayMs(10);
    Set_Enable_Low
}

//TODO LCDWrite (#LCDPort, char (just a one byte number), INSTR or DATA modes)
void lcd8bits_write(unsigned char mode, unsigned char CmdChar) {
    if(mode==CMD_MODE) Set_Command_Mode //LCDControlPort->OUT = (LCDControlPort->OUT) & (~(0b1<<LCDRSPin));
    else {Set_Data_Mode; }
    DelayMs(10);
    LCDDataPort->OUT = CmdChar;
    LCD_STROBE(); // Write 8 bits of data on D7-0
}

//TODO PrintChar(#LCDPort, char); calls LCDWrite with this and DATA mode
void lcd_putch(char character) {
    lcd8bits_write(DATA_MODE, character);
}

//TODO PrintString(#LCDPort, char *); iterate through chars calling Print Char allow a certain delay between chars
//  TODO also enable LCD scrolling if song name or artist name will run off the display (check if the string being sent to LCD will run out of space (maybe make main in charge of this with an interupt handler and make a function that shifts the LCD)
void lcd_puts(char *string) {
    while (*string != 0){ // Last character in a C-language string is alway "0" (ASCII NULL character)
        lcd8bits_write(DATA_MODE, *string);
        string++;
    }
}

//TODO Add fucntions that manipulate address to change line and position on screen when we want or just display things where we want them

void lcd_SetLineNumber(unsigned char position) {
    lcd8bits_write(CMD_MODE, 0x80 | position); // The "cursor move" command is indicated by MSB=1 (0x80)
    // followed by the panel position address (0x00- 0x7F)
}

void lcd_clear(void) {
    lcd8bits_write(CMD_MODE, LCDCMD_ClearDisplay);
    DelayMs(2);
}

void DelayMs(unsigned int nrms) {
    unsigned int i, j;
    for (j = 0; j < nrms; j++)
        for (i = 0; i < 20; i++);
}
