#include "msp.h"

#include "LCDDriver.h"
#include "SpeakerDriver.h"
#include "StepperDriver.h"
#include "SpeakerDriver.h"
#include "SwitchDriver.h"
#include "NoteDefs.h"

/**
 * TODO: Main program logic goes in this file each individual function of our drivers should be handled in their individual Driver Files
 * main.c
 */


//TODO create Timerinit for Note Duration Timer


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//howdy
}

//TODO Create ISR for Note Durations
