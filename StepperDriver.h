/*
 * StepperDriver.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef STEPPERDRIVER_H_
#define STEPPERDRIVER_H_

#include "global.h"

#define INIT_PERIOD                     29297//TODO Change these values
#define STEP_SEQ_CNT                    8//TODO Change these values


extern void initStepperMotor(void);
extern void enableStepperMotor(void);
extern void disableStepperMotor(void);

#endif /* STEPPERDRIVER_H_ */
