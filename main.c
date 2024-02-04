#include "msp.h"


/**
 * TODO: Main program logic goes in this file each individual function of our drivers should be handled in their individual Driver Files
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//howdy
}

