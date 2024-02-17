/*
 * MagnetSwitchPin.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "SwitchDriver.h"

SwitchState CheckMagnetSwitchPin(void){
    char switchValue;
    switchValue = (MagnetSwitchPort-> IN) & MagnetSwitchPin;

    if (switchValue==0){
        debounce();
        return Pressed;
    }
    else {
        debounce();
        return NotPressed;
    }
}

void MagnetSwitchPinInit(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask){
    port->SEL0 = (port->SEL0) & ~PinBitmask;
    port->SEL1 = (port->SEL1) & ~PinBitmask;
    port->DIR = (port->DIR) & ~PinBitmask;

    port->REN = (port->REN) | PinBitmask;
    port->OUT = (port->OUT) | PinBitmask;

}

void debounce(void){
    //debounce the correct way? maybe
}
