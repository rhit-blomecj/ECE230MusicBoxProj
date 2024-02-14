/*
 * StepperDriver.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "StepperDriver.h"

const uint8_t stepperSequence[STEP_SEQ_CNT] = {0b0001, 0b0011, 0b0010, 0b0110, 0b0100, 0b1100, 0b1000, 0b1001};
uint16_t stepPeriod = INIT_PERIOD;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t currentStep = 0;

void initStepperMotor(void) {//TODO maybe edit so this takes inputs and we can have multiple Steppers setup but we will just be fine with this for now
    StepperPort->SEL0 &= ~StepperBitmask;
    StepperPort->SEL1 &= ~StepperBitmask;
    StepperPort->DIR |= StepperBitmask;

    StepperPort->OUT &= ~StepperBitmask;//this initializes us to all zeroes in our step sequence this may or may not be correct

    StepperTimer->CCR //TODO setup the stepper CCR registers and CCTL registers
    StepperTimer->CCTL //I want to do Continuous mode and move the

    StepperTimer->CTL //TODO setup source clocks and all that since I want this to match up with bpm then maybe we set this up to be with the same source clock
    StepperTimer->EX0 //again will probably setup to mimic note duration timer and follow how it does its stuff might scale it differently so it doesn't appear like this is spinning a lot slower

    NVIC->ISER[0] |= (1 << TA3_0_IRQn); //TODO change this if I want it to interrupt on different CCR unit intervals but htis enables interrupts
}

void enableStepperMotor(void) {
    //TODO I may want it in continuous mode still undecided
    // configure Timer_A3 in Up Mode (leaving remaining configuration unchanged)
    TIMER_A3->CTL |= ;
    TIMER_A3->CTL &= ;
}

void disableStepperMotor(void) {
    //  Configure Timer_A3 in Stop Mode (leaving remaining configuration unchanged)
    //TODO set this up to use the defined bitmasks form msp drivers
    TIMER_A3->CTL &= 0xFFCD;//clr both mode bits
}

void step(void) {
    currentStep = (currentStep + 1) % STEP_SEQ_CNT;  // increment to next step position
//    if(currentStep == 255){//TODO I want to revisit my logic here I remember it had to do with overflow but still somehting I want to think about
//        currentStep = STEP_SEQ_CNT + 1;
//    }
    // update output port for current step pattern
    StepperPort->OUT = (StepperPort->OUT & ~StepperBitmask) | (stepperSequence[currentStep] << 4);//TODO check if this is now accurate to rotate Stepper
}

// Timer A3 CCR0 interrupt service routine
void TA3_0_IRQHandler(void)//TODO if I want to use the n handler change this
{

    //Clear flag
       TIMER_A3->CCTL[0] &= ~(0x0001);//TODO use msp bitmasks

        step();//only going to be using this feature so I don't need to think about clockwise vs counterclockwise


}
