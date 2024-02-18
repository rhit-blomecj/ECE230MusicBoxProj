/*
 * verification.h
 *
 *  Created on: Feb 18, 2024
 *      Author: blomecj
 */

#ifndef VERIFICATION_H_
#define VERIFICATION_H_
#include "msp.h"

#define verificationLEDPort P2
#define RED_PIN             1<<1
#define GREEN_PIN           1<<2
#define BLUE_PIN            1<<3

extern void initVerificationLEDs(void);

extern void toggleRed(void);
extern void toggleGreen(void);
extern void toggleBlue(void);

#endif /* VERIFICATION_H_ */
