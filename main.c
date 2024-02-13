

/**
 * TODO: Main program logic goes in this file each individual function of our drivers should be handled in their individual Driver Files
 * main.c
 */
#include "main.h"



//TODO file in out maybe


//TODO create Timerinit for Note Duration Timer

void NoteDurationSetup(void){
    configLFXT();//setup Timer A

    NoteDurationTimer->CCTL[1] = TIMER_A_CCTLN_CCIE;//OUTMOD TOGGLE Interupt enabled

    NoteDurationTimer->CCTL[2] = TIMER_A_CCTLN_CCIE;

    NoteDurationTimer->CCTL[3] = TIMER_A_CCTLN_CCIE;

    NoteDurationTimer->CCTL[4] = TIMER_A_CCTLN_CCIE;

    //use Aclk 20 prescalar means 1638 ticks per second
    SpeakerFreqTimer->CTL = TIMER_A_CTL_MC_2 | TIMER_A_CTL_ID_2 | TIMER_A_CTL_TASSEL_1 | TIMER_A_CTL_CLR;
    SpeakerFreqTimer->EX0 = TIMER_A_EX0_IDEX__5;

    NVIC->ISER[0] |= 1<<TA2_N_IRQn;//NVIC enable interrupt
}

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
void TA2_N_IRQHandler(void){
    //Soprano
    if(NoteDurationTimer->CCTL[1] & TIMER_A_CCTLN_CCIFG){
        NoteDurationTimer->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;

        if(soprano_insert_rest){
            NoteDurationTimer->CCR[1] += NoteDuration[];
        }
        else{
            NoteDurationTimer->CCR[1] += NoteSeparatorTicks;
        }

    }

    //Alto
    if(NoteDurationTimer->CCTL[2] & TIMER_A_CCTLN_CCIFG){
        NoteDurationTimer->CCTL[2] &= ~TIMER_A_CCTLN_CCIFG;

    }

    //Tenor
    if(NoteDurationTimer->CCTL[3] & TIMER_A_CCTLN_CCIFG){
        NoteDurationTimer->CCTL[3] &= ~TIMER_A_CCTLN_CCIFG;

    }

    //Bass
    if(NoteDurationTimer->CCTL[4] & TIMER_A_CCTLN_CCIFG){
        NoteDurationTimer->CCTL[4] &= ~TIMER_A_CCTLN_CCIFG;

    }

}
