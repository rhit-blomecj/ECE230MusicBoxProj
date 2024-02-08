/*
 * SpeakerDriver.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef SPEAKERDRIVER_H_
#define SPEAKERDRIVER_H_

#include "global.h"

//will need clock speed I'm setting the FreqTimer to
//after prescalar SpeakerFreqClock should be 1MHz
#define SpeakerFreqClockPrescalar 48
#define SpeakerFreqClockFreq 48000000/SpeakerFreqClockPrescalar //since using our normal HFXT configuration the clock will be 48000000


extern void initSpeakerFreqTimer();
extern void initSpeaker(void * port, char PinBitmask);

#endif /* SPEAKERDRIVER_H_ */
