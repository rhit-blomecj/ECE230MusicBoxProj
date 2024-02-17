/*
 * SwitchDriver.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef SWITCHDRIVER_H_
#define SWITCHDRIVER_H_

#include "global.h"

#define debounceDelayLoops 1500//should give me ~5ms debounce assuming 3MHz MCLK (Which I made a change to HFXT to make this work)

typedef enum _SwitchState {Pressed, NotPressed} SwitchState;

extern SwitchState CheckSwitch(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask);

extern void SwitchInit(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask);

extern void SwitchDebounce(void);

#endif /* SWITCHDRIVER_H_ */
