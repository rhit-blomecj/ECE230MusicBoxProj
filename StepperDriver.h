/*
 * StepperDriver.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef STEPPERDRIVER_H_
#define STEPPERDRIVER_H_

#include "global.h"

//#define INIT_PERIOD                     29297//TODO Change these values
#define STEP_SEQ_CNT                    4//TODO Change these values

extern void initStepperTimer(void);
extern void initStepperMotor(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask);
extern void enableStepperMotor(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask) ;
extern void disableStepperMotor(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask);

#endif /* STEPPERDRIVER_H_ */
