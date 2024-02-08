/*
 * SpeakerDriver.c
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


//TODO create initSpeaker(Port#, PinBitmask) you will need to init each speaker individually
void initSpeaker(void * port, char PinBitmask){

}

//TODO create playFrequency(Port#, PinBitmask, Freq) to enable note changing


//TODO Create Freq ISR/ISRs if we use both CCR0 and any of the other ones
//ISR FLOW
//  if/switch statement to choose the proper CCR unit
//  clear appropriate int Flag
//  move CCR unit up another half period
//  return to normal program flow
