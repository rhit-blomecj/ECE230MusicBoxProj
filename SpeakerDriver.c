/* TODO more code documentation
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

void initSpeakerFreqTimer(){//TODO write in its entirety

#ifdef Speaker1
        SpeakerFreqTimer->CCTL[1] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;//OUTMOD TOGGLE Interupt enabled
        Speaker1Ticks = 0;
        playFrequency(1, FrequencyG4);
    #endif

    #ifdef Speaker2
        SpeakerFreqTimer->CCTL[2] = TIMER_A_CCTLN_OUTMOD_4  | TIMER_A_CCTLN_CCIE;
        Speaker2Ticks = 0;
        playFrequency(2, FrequencyE4);
    #endif

    #ifdef Speaker3
        SpeakerFreqTimer->CCTL[3] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker3Ticks = 0;
        playFrequency(3, FrequencyC3);
    #endif

    #ifdef Speaker4
        SpeakerFreqTimer->CCTL[4] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker4Ticks = 0;
        playFrequency(4, FrequencyG3);
    #endif

    #ifdef Speaker5
        SpeakerFreqTimer->CCTL[5] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker5Ticks = 0;
        playFrequency(5, FrequencyE3);
    #endif

    #ifdef Speaker6
        SpeakerFreqTimer->CCTL[6] = TIMER_A_CCTLN_OUTMOD_4 | TIMER_A_CCTLN_CCIE;
        Speaker6Ticks = 0;
        playFrequency(6, FrequencyC2);
    #endif
        //this should be good for now currently my plan is to not care about CCR[0] because it needs a separate interrupt handler

    // prescale of 48
    //experiment with adding this I think this is the overflow flag but if other things break then I can put it back TIMER_A_CTL_IE
    SpeakerFreqTimer->CTL = TIMER_A_CTL_MC_2 | TIMER_A_CTL_ID_3 | TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_CLR;//bitmask to set MC to be UP counter TASSEL to use SMCLCK prescalar 4
    SpeakerFreqTimer->EX0 = TIMER_A_EX0_IDEX__6;



        //TODO might need to add NVIC assignments I would actually have to read up on that to see if that is a global interrupt enable thing or if I need to flip one of the bits for each of the CCR units
}



/*
 *
 */
//TODO create initSpeaker(Port#, PinBitmask) you will need to init each speaker individually
void initSpeaker(void * port, char PinBitmask){

    port->DIR |= PinBitmask;            // set pin as output
    port->SEL1 &= ~PinBitmask;          // Option 0b10 because that is where premapped Timer Outputs are
    port->SEL0 |= PinBitmask;           //

    //it is the job of the caller to make sure we are in a mapped pin
    //it is also up to them to
}


int freqToTicks(float Freq){
    //(1000000L1ticks/1sec) * (1sec/50L2ticks)
    return (int)(SpeakerFreqClockFreq/Freq);
}

//TODO create playFrequency(int CCRnumber(basically must be speaker number), Freq) to enable note changing
void playFrequency(int SpeakNum, float Freq){
    switch (speakNum){//TODO: add case 0 later for if we get around to setting up CCR0 support
    case 1:
        Speaker1Ticks = freqToTicks(Freq)/2;
        break;
    case 2:
        Speaker2Ticks = freqToTicks(Freq/2);
        break;
    case 3:
        Speaker3Ticks = freqToTicks(Freq/2);
        break;
    case 4:
        Speaker4Ticks = freqToTicks(Freq)/2;
        break;
    case 5:
        Speaker5Ticks = freqToTicks(Freq)/2;
        break;
    case 6:
        Speaker6Ticks = freqToTicks(Freq)/2;
        break;
    default:
        break;


    }
}

//TODO Create Freq ISR/ISRs if we use both CCR0 and any of the other ones
//ISR FLOW
//  if/switch statement to choose the proper CCR unit
//  clear appropriate int Flag
//  move CCR unit up another half period
//  return to normal program flow
#if SpeakerFreqTimer == TIMER_A0 //check other thing later this is what we are actually using so this should be the only one that matters
    void TA1_N_IRQHandler (void){//for playing frequencies in an IRQ will need to decide what interupt is using us then do the proper operations
    #ifdef Speaker1
        if(TIMER_A1->CCTL[1] & TIMER_A_CCTLN_CCIFG){
            TIMER_A1->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;
            TIMER_A1 -> CCR[1] += Speaker1Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker2
        if(TIMER_A1->CCTL[2] & TIMER_A_CCTLN_CCIFG){
            TIMER_A1->CCTL[2] &= ~TIMER_A_CCTLN_CCIFG;
            TIMER_A1 -> CCR[2] += Speaker2Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker3
        if(TIMER_A1->CCTL[3] & TIMER_A_CCTLN_CCIFG){
            TIMER_A1->CCTL[3] &= ~TIMER_A_CCTLN_CCIFG;
            TIMER_A1 -> CCR[3] += Speaker3Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker4
        if(TIMER_A1->CCTL[4] & TIMER_A_CCTLN_CCIFG){
            TIMER_A1->CCTL[4] &= ~TIMER_A_CCTLN_CCIFG;
            TIMER_A1 -> CCR[4] += Speaker4Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker5
        if(TIMER_A1->CCTL[5] & TIMER_A_CCTLN_CCIFG){
            TIMER_A1->CCTL[5] &= ~TIMER_A_CCTLN_CCIFG;
            TIMER_A1 -> CCR[5] += Speaker5Ticks;//add number of ticks so it will repeat freq
        }
    #endif

    #ifdef Speaker6
        if(TIMER_A1->CCTL[6] & TIMER_A_CCTLN_CCIFG){
            TIMER_A1->CCTL[6] &= ~TIMER_A_CCTLN_CCIFG;
            TIMER_A1 -> CCR[6] += Speaker6Ticks;//add number of ticks so it will repeat freq
        }
    #endif
    }
#endif

