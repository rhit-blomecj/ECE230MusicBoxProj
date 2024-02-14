

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

	while(1){
	    if(boxClosed){//Box closed needs enum defined and should be public
	        //All Timers to Stop Mode

	    }
	    if(boxOpen){//might be able to just make this an else statement
	        //set timers back to continuous mode
	    }

//	    if(buttonPressed){ not yet decided but this might be a song switch
//
//	    }
	}

}

int nextNote = 0;
int onebeatticks =0;

char insert_rest_soprano = 1;
char insert_rest_alto = 1;
char insert_rest_tenor = 1;
char insert_rest_bass = 1;


//TODO Create ISR for Note Durations
void TA2_N_IRQHandler(void){
    //Soprano
    if(NoteDurationTimer->CCTL[1] & TIMER_A_CCTLN_CCIFG){
        NoteDurationTimer->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;//clear flag

        if(!insert_rest_soprano){//check if we need to
            currentNote ++;
            if(SopranoNoteDuration[currentNote] == NULL){
                currentNote=0;
            }

            //call playNote function

            NoteDurationTimer->CCR[1] += onebeatticks*SopranoNoteDuration[currentNote];//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
            insert_rest_soprano = 1;
        }
        else{
            SpeakerPort->DIR &= ~(Soprano); //pause music (changes speaker port to input mode)
            NoteDurationTimer->CCR[1] += NoteSeparatorTicks;
            insert_rest_soprano = 0;
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
