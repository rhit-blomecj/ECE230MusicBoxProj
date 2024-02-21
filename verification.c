/*
 * verification.c
 *
 *  Created on: Feb 18, 2024
 *      Author: blomecj
 */
#include "verification.h"

void initVerificationLEDs(void){
    verificationLEDPort->DIR |= (RED_PIN | GREEN_PIN | BLUE_PIN);
    verificationLEDPort->SEL0 &= ~(RED_PIN | GREEN_PIN | BLUE_PIN);
    verificationLEDPort->SEL1 &= ~(RED_PIN | GREEN_PIN | BLUE_PIN);
    verificationLEDPort->OUT &= ~(RED_PIN | GREEN_PIN | BLUE_PIN);//start low
}

void toggleRed(void){
    verificationLEDPort->OUT ^= RED_PIN;
}

void toggleGreen(void){
    verificationLEDPort->OUT ^= GREEN_PIN;
}

void toggleBlue(void){
    verificationLEDPort->OUT ^= BLUE_PIN;
}
