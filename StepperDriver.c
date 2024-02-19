/*
 * StepperDriver.c
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
#include "StepperDriver.h"

#ifdef Stepper1
uint8_t stepper1Sequence[STEP_SEQ_CNT] = {Stepper1_pin1, Stepper1_pin2, Stepper1_pin3, Stepper1_pin4};
uint16_t stepper1Period = 80;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t stepper1CurrentStep = 0;
#endif

#ifdef Stepper2
uint8_t stepper2Sequence[STEP_SEQ_CNT] = {Stepper2_pin1, Stepper2_pin2, Stepper2_pin3, Stepper2_pin4};
uint16_t stepper2Period = 80;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t stepper2CurrentStep = 0;
#endif

#ifdef Stepper3
uint8_t stepper3Sequence[STEP_SEQ_CNT] = {Stepper3_pin1, Stepper3_pin2, Stepper3_pin3, Stepper3_pin4};
uint16_t stepper3Period = 80;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t stepper3CurrentStep = 0;
#endif

#ifdef Stepper4
uint8_t stepper4Sequence[STEP_SEQ_CNT] = {Stepper4_pin1, Stepper4_pin2, Stepper4_pin3, Stepper4_pin4};
uint16_t stepper4Period = 80;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t stepper4CurrentStep = 0;
#endif

#ifdef Stepper5
uint8_t stepper5Sequence[STEP_SEQ_CNT] = {Stepper5_pin1, Stepper5_pin2, Stepper5_pin3, Stepper5_pin4};
uint16_t stepper5Period = 80;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t stepper5CurrentStep = 0;
#endif

#ifdef Stepper6
uint8_t stepper6Sequence[STEP_SEQ_CNT] = {Stepper6_pin1, Stepper6_pin2, Stepper6_pin3, Stepper6_pin4};
uint16_t stepper6Period = 80;//init period will be set to whatever BPM of the song is and step Period will be updated to whatever matches with bpm
uint8_t stepper6CurrentStep = 0;
#endif

void initStepperTimer(void){
    //would need to run the LFXTconfig if I didn't already for speakers
    #ifdef Stepper1
        StepperTimer->CCTL[1] = TIMER_A_CCTLN_CCIE;//Interupt enabled
        StepperTimer->CCR[1] = stepper1Period;
    #endif

    #ifdef Stepper2
        StepperTimer->CCTL[2] = TIMER_A_CCTLN_CCIE;
        StepperTimer->CCR[2] = stepper2Period;
    #endif

    #ifdef Stepper3
        StepperTimer->CCTL[3] = TIMER_A_CCTLN_CCIE;
        StepperTimer->CCR[3] = stepper3Period;
    #endif

    #ifdef Stepper4
        StepperTimer->CCTL[4] = TIMER_A_CCTLN_CCIE;
        StepperTimer->CCR[4] = stepper4Period;
    #endif

    #ifdef Stepper5
        StepperTimer->CCTL[5] = TIMER_A_CCTLN_CCIE;
        StepperTimer->CCR[5] = stepper5Period;
    #endif

    #ifdef Stepper6
        StepperTimer->CCTL[6] = TIMER_A_CCTLN_CCIE;
        StepperTimer->CCR[6] = stepper6Period;
    #endif






    StepperTimer->CTL = TIMER_A_CTL_MC_2 | TIMER_A_CTL_TASSEL_1 | TIMER_A_CTL_CLR;//continuous using ACLK
    StepperTimer->EX0 = 0; //prescale of one

    //for when we are less time constrained I would want to setup the NVIC statement
    //in #if to make this code more generalized and it would be able to operate off of different timers
    NVIC->ISER[0] |= (1 << TA3_N_IRQn);


}

void initStepperMotor(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask) {
    port->SEL0 &= ~stepperMask;
    port->SEL1 &= ~stepperMask;
    port->DIR |= stepperMask;

    port->OUT &= ~stepperMask;//this initializes us to all zeroes in our step sequence this may or may not be correct
}

void enableStepperMotor(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask) {
    // configure the specific
//   switch (stepperMask){
//   #ifdef Stepper1
//       case Stepper1:
//           StepperTimer->CCTL[1] |= TIMER_A_CCTLN_CCIE;//enable interrupts vs disable interupts
//           stepper1CurrentStep = 0;
//           port->OUT = (port->OUT & ~stepperMask) | stepper1Sequence[stepper1CurrentStep];//clear its outs so we can set the stepper sequence on a clean slate
//           break;
//   #endif
//
//   #ifdef Stepper2
//       case Stepper2:
//           StepperTimer->CCTL[2] |= TIMER_A_CCTLN_CCIE;
//           stepper2CurrentStep = 0;
//           port->OUT = (port->OUT & ~stepperMask) | stepper2Sequence[stepper2CurrentStep];
//           break;
//   #endif
//
//   #ifdef Stepper3
//       case Stepper3:
//           StepperTimer->CCTL[3] |= TIMER_A_CCTLN_CCIE;
//           stepper3CurrentStep = 0;
//           port->OUT = (port->OUT & ~stepperMask) | stepper3Sequence[stepper3CurrentStep];
//           break;
//   #endif
//
//   #ifdef Stepper4
//       case Stepper4:
//           StepperTimer->CCTL[4] |= TIMER_A_CCTLN_CCIE;
//           stepper4CurrentStep = 0;
//           port->OUT = (port->OUT & ~stepperMask) | stepper4Sequence[stepper4CurrentStep];
//           break;
//   #endif
//
//   #ifdef Stepper5
//       case Stepper5:
//           StepperTimer->CCTL[5] |= TIMER_A_CCTLN_CCIE;
//           stepper5CurrentStep = 0;
//           port->OUT = (port->OUT & ~stepperMask) | stepper5Sequence[stepper5CurrentStep];
//           break;
//   #endif
//
//   #ifdef Stepper6
//       case Stepper6:
//           StepperTimer->CCTL[6] |= TIMER_A_CCTLN_CCIE;
//           stepper6CurrentStep = 0;
//           port->OUT = (port->OUT & ~stepperMask) | stepper6Sequence[stepper6CurrentStep];
//           break;
//   #endif
//
//       default:
//           break;
//       }

    StepperTimer->CTL |= (TIMER_A_CTL_MC_2);
    stepper1CurrentStep = 0;
    port->OUT = (port->OUT & ~stepperMask) | stepper1Sequence[stepper1CurrentStep];
}

void disableStepperMotor(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask) {

//    switch (stepperMask){
//    #ifdef Stepper1
//        case Stepper1:
//            StepperTimer->CCTL[1] &= ~TIMER_A_CCTLN_CCIE;//enable interrupts vs disable interupts
//            break;
//    #endif
//
//    #ifdef Stepper2
//        case Stepper2:
//            StepperTimer->CCTL[2] &= ~TIMER_A_CCTLN_CCIE;
//            break;
//    #endif
//
//    #ifdef Stepper3
//        case Stepper3:
//            StepperTimer->CCTL[3] &= ~TIMER_A_CCTLN_CCIE;
//            break;
//    #endif
//
//    #ifdef Stepper4
//        case Stepper4:
//            StepperTimer->CCTL[4] &= ~TIMER_A_CCTLN_CCIE;
//            break;
//    #endif
//
//    #ifdef Stepper5
//        case Stepper5:
//            StepperTimer->CCTL[5] &= ~TIMER_A_CCTLN_CCIE;
//            break;
//    #endif
//
//    #ifdef Stepper6
//        case Stepper6:
//            StepperTimer->CCTL[6] &= ~TIMER_A_CCTLN_CCIE;
//            break;
//    #endif
//        default:
//            break;
//
//
//        }
    StepperTimer->CTL &= ~(TIMER_A_CTL_MC_2);
    port->OUT &= ~stepperMask;//clear its outs so we aren't holding a position for no reason

}

 void setRPM(float rpm, int stepperMask) {
     //If I think about BPM->RPM 40 BPM is 2 RPM and 240 BPM is 12 RPM
     //needs  implemented but 2rpm is 480ticks - 12 rpm is 80 ticks
     int calculatedTicks = rpmConstant/rpm;

     switch (stepperMask){
         #ifdef Stepper1
             case Stepper1:
                 stepper1Period = calculatedTicks;
                 break;
         #endif

         #ifdef Stepper2
             case Stepper2:
                 stepper2Period = calculatedTicks;
                 break;
         #endif

         #ifdef Stepper3
             case Stepper3:
                 stepper3Period = calculatedTicks;
                 break;
         #endif

         #ifdef Stepper4
             case Stepper4:
                 stepper4Period = calculatedTicks;
                 break;
         #endif

         #ifdef Stepper5
             case Stepper5:
                 stepper5Period = calculatedTicks;
                 break;
         #endif

         #ifdef Stepper6
             case Stepper6:
                 stepper6Period = calculatedTicks;
                 break;
         #endif
             default:
                 break;


             }



 }

void step(DIO_PORT_Odd_Interruptable_Type* port, int stepperMask) {

    switch (stepperMask){
    #ifdef Stepper1
        case Stepper1:
            StepperTimer->CCTL[1] |= TIMER_A_CCTLN_CCIE;//enable interrupts vs disable interupts
            stepper1CurrentStep = (stepper1CurrentStep + 1) % STEP_SEQ_CNT;
            port->OUT = (port->OUT & ~stepperMask) | stepper1Sequence[stepper1CurrentStep];//clear its outs so we can set the stepper sequence on a clean slate
            break;
    #endif

    #ifdef Stepper2
        case Stepper2:
            StepperTimer->CCTL[2] |= TIMER_A_CCTLN_CCIE;
            stepper2CurrentStep = (stepper2CurrentStep + 1) % STEP_SEQ_CNT;
            port->OUT = (port->OUT & ~stepperMask) | stepper2Sequence[stepper2CurrentStep];
            break;
    #endif

    #ifdef Stepper3
        case Stepper3:
            StepperTimer->CCTL[3] |= TIMER_A_CCTLN_CCIE;
            stepper3CurrentStep = (stepper3CurrentStep + 1) % STEP_SEQ_CNT;
            port->OUT = (port->OUT & ~stepperMask) | stepper3Sequence[stepper3CurrentStep];
            break;
    #endif

    #ifdef Stepper4
        case Stepper4:
            StepperTimer->CCTL[4] |= TIMER_A_CCTLN_CCIE;
            stepper4CurrentStep = (stepper4CurrentStep + 1) % STEP_SEQ_CNT;
            port->OUT = (port->OUT & ~stepperMask) | stepper4Sequence[stepper4CurrentStep];
            break;
    #endif

    #ifdef Stepper5
        case Stepper5:
            StepperTimer->CCTL[5] |= TIMER_A_CCTLN_CCIE;
            stepper5CurrentStep = (stepper5CurrentStep + 1) % STEP_SEQ_CNT;
            port->OUT = (port->OUT & ~stepperMask) | stepper5Sequence[stepper5CurrentStep];
            break;
    #endif

    #ifdef Stepper6
        case Stepper6:
            StepperTimer->CCTL[6] |= TIMER_A_CCTLN_CCIE;
            stepper6CurrentStep = (stepper6CurrentStep + 1) % STEP_SEQ_CNT;
            port->OUT = (port->OUT & ~stepperMask) | stepper6Sequence[stepper6CurrentStep];
            break;
    #endif

        default:
            break;
        }


}

// Timer A3 CCR0 interrupt service routine
void TA3_N_IRQHandler(void)
{

    #ifdef Stepper1
        if(StepperTimer->CCTL[1] & TIMER_A_CCTLN_CCIFG){
            StepperTimer->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;
            StepperTimer -> CCR[1] += stepper1Period;//add number of ticks so it will repeat freq
            step(Stepper1_port, Stepper1);//technically this is not generalized in the way I was aiming for but I'll work on that if I have time at the end of the project
#ifdef VERIFICATION_H_
        toggleGreen();//allows verification of stepper speed (basically verify how long it takes to do certain number of steps)
#endif
        }
    #endif

    #ifdef Stepper2
        if(StepperTimer->CCTL[2] & TIMER_A_CCTLN_CCIFG){
            StepperTimer->CCTL[2] &= ~TIMER_A_CCTLN_CCIFG;
            StepperTimer -> CCR[2] += stepper2Period;//add number of ticks so it will repeat freq
            step(Stepper2_port, Stepper2);
        }
    #endif

    #ifdef Stepper3
        if(StepperFreqTimer->CCTL[3] & TIMER_A_CCTLN_CCIFG){
            StepperTimer->CCTL[3] &= ~TIMER_A_CCTLN_CCIFG;
            StepperTimer -> CCR[3] += stepper3Period;//add number of ticks so it will repeat freq
            step(Stepper3_port, Stepper3);
        }
    #endif

    #ifdef Stepper4
        if(StepperTimer->CCTL[4] & TIMER_A_CCTLN_CCIFG){
            StepperTimer->CCTL[4] &= ~TIMER_A_CCTLN_CCIFG;
            StepperTimer -> CCR[4] += stepper4Period;//add number of ticks so it will repeat freq
            step(Stepper4_port, Stepper4);
        }
    #endif

    #ifdef Stepper5
        if(StepperTimer->CCTL[5] & TIMER_A_CCTLN_CCIFG){
            StepperTimer->CCTL[5] &= ~TIMER_A_CCTLN_CCIFG;
            StepperTimer -> CCR[5] += stepper5Period;//add number of ticks so it will repeat freq
            step(Stepper5_port, Stepper5);
        }
    #endif

    #ifdef Stepper6
        if(StepperTimer->CCTL[6] & TIMER_A_CCTLN_CCIFG){
            StepperTimer->CCTL[6] &= ~TIMER_A_CCTLN_CCIFG;
            StepperTimer -> CCR[6] += stepper6Period;//add number of ticks so it will repeat freq
            step(Stepper6_port, Stepper6);
        }
    #endif
    }
