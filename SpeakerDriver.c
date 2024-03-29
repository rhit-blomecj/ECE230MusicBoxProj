/*
 * SpeakerDriver.c
 *
 * You need to #define SpeakerFreqTimer as one of the A timers so we can set it up properly
 * You need to #define SpeakerX with X being a number between 1-6 this is so we can set up the interrupt to generate its frequency
 * This driver cannot support more than 6 speakers at a time and all speakers will be controlled by the same Timer
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */
//All Speakers initialized in this driver are required to have frequencies generated by the same clock
//This means that the limit of our number of speakers is the number of CCR units
//Clock should be set to Continuous Mode
//Relevant CCR Units (we can use #ifdefs to filter)
//  OutMod=Toggle
//  interupt enabled
//

//The ISRs will be in #if FreqTimer == Timer_A0 and we will just have a lot of those (probably only setup for TimerA timers and that will just need to be said in documentation)
//#ifdef SpeakerX blocks where X corresponds to the number of the CCR unit it should be controlled by should surround cases in switch/if statement
//when SpeakerX is defined it should be defined with a bitmask for a pin
#include "SpeakerDriver.h"

#ifdef Speaker1
   int Speaker1Ticks;
#endif

#ifdef Speaker2
   int Speaker2Ticks;
#endif

#ifdef Speaker3
   int Speaker3Ticks;
#endif

#ifdef Speaker4
   int Speaker4Ticks;
#endif

#ifdef Speaker5
   int Speaker5Ticks;
#endif

#ifdef Speaker6
   int Speaker6Ticks;
#endif

void initSpeakerFreqTimer(void){

    #ifdef Speaker1
        SpeakerFreqTimer->CCTL[1] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;//OUTMOD TOGGLE Interupt enabled
        Speaker1Ticks = 0;
    #endif

    #ifdef Speaker2
        SpeakerFreqTimer->CCTL[2] = TIMER_A_CCTLN_OUTMOD_4  | TIMER_A_CCTLN_CCIE;
        Speaker2Ticks = 0;
    #endif

    #ifdef Speaker3
        SpeakerFreqTimer->CCTL[3] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker3Ticks = 0;
        playFrequency(Speaker3, C3);
    #endif

    #ifdef Speaker4
        SpeakerFreqTimer->CCTL[4] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker4Ticks = 0;
    #endif

    #ifdef Speaker5
        SpeakerFreqTimer->CCTL[5] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker5Ticks = 0;
    #endif

    #ifdef Speaker6
        SpeakerFreqTimer->CCTL[6] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker6Ticks = 0;
    #endif

    // prescale of 48
    //experiment with adding this I think this is the overflow flag but if other things break then I can put it back TIMER_A_CTL_IE
    SpeakerFreqTimer->CTL = TIMER_A_CTL_MC_2 | TIMER_A_CTL_ID_3 | TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_CLR;//bitmask to set MC to be Continuous counter TASSEL to use SMCLCK prescalar 4
    SpeakerFreqTimer->EX0 = TIMER_A_EX0_IDEX__6;

    configHFXT();
    //would want to generalize using #if and timers
    NVIC->ISER[0] |= 1<<TA0_N_IRQn;
}


void stopAllSpeakers(void){
    SpeakerFreqTimer->CTL &= ~(TIMER_A_CTL_MC_2  | TIMER_A_CTL_CLR);// sets timer to stop mode and clrs all TAxRs
}

void startAllSpeakers(void){
    SpeakerFreqTimer->CTL |= TIMER_A_CTL_MC_2;// sets timer to continuous mode
}


/*
 *
 *
 */
void initSpeaker(DIO_PORT_Even_Interruptable_Type* port, char PinBitmask){

    port->DIR |= PinBitmask;            // set pin as output
    port->SEL1 &= ~PinBitmask;          // Option 0b01 because that is where premapped Timer Outputs are
    port->SEL0 |= PinBitmask;           //

    //it is the job of the caller to make sure we are in a mapped pin
    //it is also up to them to
}


int freqToTicks(float Freq){
    //(1000000L1ticks/1sec) * (1sec/50L2ticks)
    return (int)(SpeakerFreqClockFreq/Freq);
}

void playFrequency(int SpeakNum, float Freq){
    switch (SpeakNum){
#ifdef Speaker1
    case Speaker1:
        Speaker1Ticks = (int) (freqToTicks(Freq)/2);
        break;
#endif

#ifdef Speaker2
    case Speaker2:
        Speaker2Ticks = (int) (freqToTicks(Freq)/2);
        break;
#endif

#ifdef Speaker3
    case Speaker3:
        Speaker3Ticks = (int) (freqToTicks(Freq)/2);
        break;
#endif

#ifdef Speaker4
    case Speaker4:
        Speaker4Ticks = (int) (freqToTicks(Freq)/2);
        break;
#endif

#ifdef Speaker5
    case Speaker5:
        Speaker5Ticks = (int) (freqToTicks(Freq)/2);
        break;
#endif

#ifdef Speaker6
    case Speaker6:
        Speaker6Ticks = (int) (freqToTicks(Freq)/2);
        break;
#endif
    default:
        break;
    }

}

//ISR FLOW
//  if/switch statement to choose the proper CCR unit
//  clear appropriate int Flag
//  move CCR unit up another half period
//  return to normal program flow
//check other thing later this is what we are actually using so this should be the only one that matters
//#if SpeakerFreqTimer==TIMER_A0
    void TA0_N_IRQHandler (void){//for playing frequencies in an IRQ will need to decide what interupt is using us then do the proper operations
    #ifdef Speaker1
        if(SpeakerFreqTimer->CCTL[1] & TIMER_A_CCTLN_CCIFG){
            SpeakerFreqTimer->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;
            SpeakerFreqTimer -> CCR[1] += Speaker1Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker2
        if(SpeakerFreqTimer->CCTL[2] & TIMER_A_CCTLN_CCIFG){
            SpeakerFreqTimer->CCTL[2] &= ~TIMER_A_CCTLN_CCIFG;
            SpeakerFreqTimer -> CCR[2] += Speaker2Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker3
        if(SpeakerFreqTimer->CCTL[3] & TIMER_A_CCTLN_CCIFG){
            SpeakerFreqTimer->CCTL[3] &= ~TIMER_A_CCTLN_CCIFG;
            SpeakerFreqTimer -> CCR[3] += Speaker3Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker4
        if(SpeakerFreqTimer->CCTL[4] & TIMER_A_CCTLN_CCIFG){
            SpeakerFreqTimer->CCTL[4] &= ~TIMER_A_CCTLN_CCIFG;
            SpeakerFreqTimer -> CCR[4] += Speaker4Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker5
        if(SpeakerFreqTimer->CCTL[5] & TIMER_A_CCTLN_CCIFG){
            SpeakerFreqTimer->CCTL[5] &= ~TIMER_A_CCTLN_CCIFG;
            SpeakerFreqTimer -> CCR[5] += Speaker5Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker6
        if(SpeakerFreqTimer->CCTL[6] & TIMER_A_CCTLN_CCIFG){
            SpeakerFreqTimer->CCTL[6] &= ~TIMER_A_CCTLN_CCIFG;
            SpeakerFreqTimer -> CCR[6] += Speaker6Ticks;//add number of ticks so it will repeat freq
        }
    #endif
    }
//#endif

