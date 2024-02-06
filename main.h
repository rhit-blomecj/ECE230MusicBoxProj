/*
 * main.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef MAIN_H_
#define MAIN_H_

//TODO: All the ports and different port things should happen in here
//LCDDataPort should be P4
//LCD Control Pins P1.6 P1.7

//Speaker Freq Timer should be TimerA0
//Spearker Freq pins should be P2.4-P2.7 (corresponds to TA0.1-TA0.4)

//Note Duration Timer should be TimerA2
//Note Duration Timer Pins should be P5.6 P5.7 P6.6 P6.7 corresponds to (TA2.1-TA2.4)

//Stepper Timer should be TimerA3
//Stepper Output pins should be P3.0-P3.3

//For magnet switch we want to use P1.5

//TODO Save Timer A2 clockrate and stuff so we can do bpm and duration calculations
//quarter note time needs to be figured out during runtime if I want bpms that can change

#endif /* MAIN_H_ */
