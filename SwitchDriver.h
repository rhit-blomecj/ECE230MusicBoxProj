/*
 * SwitchDriver.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef SWITCHDRIVER_H_
#define SWITCHDRIVER_H_

#include "global.h"

typedef enum _SwitchState {Pressed, NotPressed} SwitchState;

extern SwitchState CheckMagnetSwitchPin(void);

extern void MagnetSwitchPinInit(DIO_PORT_Odd_Interruptable_Type* port, char PinBitmask);

#endif /* SWITCHDRIVER_H_ */
