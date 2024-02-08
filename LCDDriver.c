/*
 * LCDDriver.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "LCDDriver.h"

//TODO LCDconfig(#LCDPort)

//TODO LCDinit(#LCDPort) this should run the initialization commands I didn't get 4 bit to work so we are just doing an 8 bit driver unfortunately

//TODO LCDWrite (#LCDPort, char (just a one byte number), INSTR or DATA modes)

//TODO PrintChar(#LCDPort, char); calls LCDWrite with this and DATA mode

//TODO PrintString(#LCDPort, char *); iterate through chars calling Print Char allow a certain delay between chars
//  TODO also enable LCD scrolling if song name or artist name will run off the display (check if the string being sent to LCD will run out of space (maybe make main in charge of this with an interupt handler and make a function that shifts the LCD)

//TODO Add fucntions that manipulate address to change line and position on screen when we want or just display things where we want them


