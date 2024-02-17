/*
 * MagnetSwitchPin.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "SwitchDriver.h"

SwitchState CheckSwitch(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask){
    char switchValue;
    switchValue = (port-> IN) & PinBitmask;

    if (switchValue==0){
        return Pressed;
    }
    else {
        return NotPressed;
    }
}

void SwitchInit(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask){
    port->SEL0 &= ~PinBitmask;
    port->SEL1 &= ~PinBitmask;
    port->DIR &= ~PinBitmask;

    port->REN |= PinBitmask;//pullup resistor so when not pressed its high
    port->OUT |= PinBitmask;

}

//THIS DEBOUNCE IS ~5ms ASSUMING THAT WE DON'T CHANGE THE MCLK FROM 3MHz
void SwitchDebounce(void){
    int i;
    for(i=0; i<debounceDelayLoops; i++){
    }
}

