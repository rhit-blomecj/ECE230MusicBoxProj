/*
 * global.h
 *
 *  Created on: Feb 8, 2024
 *      Author: blomecj
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "msp.h"

//LCDDataPort should be P4
//LCD Control Pins P1.6 P1.7
#define LCDDataPort P4
#define LCDControlPort P1
#define LCDRSPin 1<<7
#define LCDEPin 1<<6

//Speaker Freq Timer should be TimerA0
//Spearker Freq pins should be P2.4-P2.7 (corresponds to TA0.1-TA0.4)
#define SpeakerFreqTimer Timer_A0
#define SpeakerPort P2
#define Speaker1 1<<7
#define Speaker2 1<<6
#define Speaker3 1<<5
#define Speaker4 1<<4

//Note Duration Timer should be TimerA2
//Note Duration Timer Pins should be P5.6 P5.7 P6.6 P6.7 corresponds to (TA2.1-TA2.4)
#define NoteDurationTimer Timer_A2
#define NoteDurationPrescalar 20
#define NoteDurationTimerFreq 32000/NoteDurationPrescalar //Hz we will set it up so this works

#define HighPort P6 //interrupt out ports for Timer_A2
#define LowPort P5

#define Speaker1Dur 1<<7
#define Speaker2Dur 1<<6
#define Speaker3Dur 1<<7
#define Speaker4Dur 1<<6

//Stepper Timer should be TimerA3
//Stepper Output pins should be P3.0-P3.3
#define StepperTimer Timer_A3 //May decide to just make this the same as the NoteDurationTimer because then we can just set an unused compare unit to be an interrupt for stepping the stepper motor
#define StepperPort P3
#define StepperBitmask 0x2D //P3 bits 0 2 3 5 our drive sequence is gonna look funky


//For magnet switch we want to use P1.5
#define MagnetSwitchPort P1
#define MagnetSwitchPin 1<<5

//Save Timer A2 clockrate and stuff so we can do bpm and duration calculations
//bpm time needs to be figured out during runtime if I want bpms that can change
//don't calculate quarter note time calculate 1 beat time when calculating


#endif /* GLOBAL_H_ */
