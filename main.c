

/**
 * TODO: Main program logic goes in this file each individual function of our drivers should be handled in their individual Driver Files
 * main.c
 */
#include "main.h"
//TODO file in out maybe


//TODO create Timerinit for Note Duration Timer


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//Speaker Setup START

	initSpeaker(SpeakerPort, Soprano);//call for all 4 speakers
	initSpeaker(SpeakerPort, Alto);
	initSpeaker(SpeakerPort, Tenor);
	initSpeaker(SpeakerPort, Bass);

	initSpeakerFreqTimer();
	//Speaker Setup END
	__enable_irq();                 // Enable global interrupt

}

//TODO Create ISR for Note Durations
