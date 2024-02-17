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
        debounce();
        return Pressed;
    }
    else {
        debounce();
        return NotPressed;
    }
}

void SwitchInit(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask){
    port->SEL0 = (port->SEL0) & ~PinBitmask;
    port->SEL1 = (port->SEL1) & ~PinBitmask;
    port->DIR = (port->DIR) & ~PinBitmask;

    port->REN = (port->REN) | PinBitmask;//pullup resistor so when not pressed its high
    port->OUT = (port->OUT) | PinBitmask;

}

void debounce(void){
    //debounce the correct way? maybe
}
