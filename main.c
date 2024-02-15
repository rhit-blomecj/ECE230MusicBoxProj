

/**
 * TODO: Main program logic goes in this file each individual function of our drivers should be handled in their individual Driver Files
 * main.c
 */
#include "main.h"

int bpm = 120;//TODO assign init values
int onebeatticks = 0;//equation to give ticks per beat

BoxState boxState;

int currentSopranoNote = 0;
int currentAltoNote = 0;
int currentTenorNote = 0;
int currentBassNote = 0;

float activeSopranoNotes[] = {C4, R, C6, C7,
                              NULL};
float activeSopranoDurations[] = {2, 2, 2, 2,
                                  NULL};


float activeAltoNotes[] = {E4, R, E6, E7,
                           NULL};
float activeAltoDurations[] = {2, 2, 2, 2,
                               NULL};


float activeTenorNotes[] = {G4, R, G6, G7,
                            NULL};
float activeTenorDurations[] = {2, 2, 2, 2,
                                NULL};


float activeBassNotes[] = {B4, R, B6, B7,
                           NULL};
float activeBassDurations[] = {2, 2, 2, 2,
                               NULL};

//might just use onebeatticks for ticks to spin the stepper to but remove some amount of prescalar so it moves like 5 times faster or something

//TODO file in out maybe


//TODO create Timerinit for Note Duration Timer
void NoteDurationSetup(void){
    configLFXT();//setup Timer A

    NoteDurationTimer->CCTL[1] = TIMER_A_CCTLN_CCIE;//OUTMOD TOGGLE Interupt enabled

    NoteDurationTimer->CCTL[2] = TIMER_A_CCTLN_CCIE;

    NoteDurationTimer->CCTL[3] = TIMER_A_CCTLN_CCIE;

    NoteDurationTimer->CCTL[4] = TIMER_A_CCTLN_CCIE;

    NoteDurationTimer->CCR[1] = 0;
    NoteDurationTimer->CCR[2] = 0;
    NoteDurationTimer->CCR[3] = 0;
    NoteDurationTimer->CCR[4] = 0;

    //use Aclk 20 prescalar means 1638 ticks per second
    NoteDurationTimer->CTL = TIMER_A_CTL_MC_2 | TIMER_A_CTL_ID_2 | TIMER_A_CTL_TASSEL_1 | TIMER_A_CTL_CLR;//the twois for interupt enable just testing
    NoteDurationTimer->EX0 = TIMER_A_EX0_IDEX__5;

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

	NoteDurationSetup();
	//Stepper Setup START
	initStepperMotor(Stepper1_port, Stepper1);

	initStepperTimer();
	//Stepper Setup END

	__enable_irq();                 // Enable global interrupt

//	SpeakerPort->DIR &= ~(Alto | Tenor | Bass);

	onebeatticks = (int)((60.0/(float)bpm)*(float)NoteDurationTimerFreq);//initialization needed to wait until here TODO  make functions to do this and do this when bpm switches

	//need to do this to start the song
	playFrequency(Soprano, activeSopranoNotes[currentSopranoNote]);
	playFrequency(Alto, activeAltoNotes[currentAltoNote]);
	playFrequency(Tenor, activeTenorNotes[currentTenorNote]);
	playFrequency(Bass, activeBassNotes[currentBassNote]);



	NoteDurationTimer->CCR[4] += (int) ((float)onebeatticks*activeSopranoDurations[currentSopranoNote]);
	NoteDurationTimer->CCR[3] += (int) ((float)onebeatticks*activeAltoDurations[currentAltoNote]);
	NoteDurationTimer->CCR[2] += (int) ((float)onebeatticks*activeTenorDurations[currentTenorNote]);
	NoteDurationTimer->CCR[1] += (int) ((float)onebeatticks*activeBassDurations[currentBassNote]);

	while(1){
	    if(boxState==Closed){//Box closed needs enum defined and should be public
	        //All Speaker Timers to Stop Mode including frequency stuff

	    }
	    if(boxState==Open){//might be able to just make this an else statement
	        //set timers back to continuous mode
	    }

//	    if(buttonPressed){ not yet decided but this might be a song switch
//
//	    }
	}

}

//int currentNote = 0; defined above
//int onebeatticks =0; defined above

char insert_rest_soprano = 1;
char insert_rest_alto = 1;
char insert_rest_tenor = 1;
char insert_rest_bass = 1;


//TODO Create ISR for Note Durations
void TA2_N_IRQHandler(void){
    char SopInt = NoteDurationTimer->CCTL[4] & TIMER_A_CCTLN_CCIFG;
    char AltInt = NoteDurationTimer->CCTL[3] & TIMER_A_CCTLN_CCIFG;
    char TenInt = NoteDurationTimer->CCTL[2] & TIMER_A_CCTLN_CCIFG;
    char BasInt = NoteDurationTimer->CCTL[1] & TIMER_A_CCTLN_CCIFG;
    //Soprano
    if(SopInt){
        NoteDurationTimer->CCTL[4] &= ~TIMER_A_CCTLN_CCIFG;//clear flag

        if(!insert_rest_soprano){//check if we need to
            currentSopranoNote ++;
            if(activeSopranoDurations[currentSopranoNote] == NULL){
                currentSopranoNote=0;
            }

            //call playNote function

            NoteDurationTimer->CCR[4] += (int) ((float)onebeatticks*activeSopranoDurations[currentSopranoNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
            playFrequency(Soprano, activeSopranoNotes[currentSopranoNote]);
            SpeakerPort->DIR |= (Soprano);//make soprano output

            insert_rest_soprano = 1;
        }
        else{
            SpeakerPort->DIR &= ~(Soprano); //speaker to input mode
            NoteDurationTimer->CCR[4] += NoteSeparatorTicks;
            insert_rest_soprano = 0;
        }
    }

    //Alto
    if(AltInt){
        NoteDurationTimer->CCTL[3] &= ~TIMER_A_CCTLN_CCIFG;

        if(!insert_rest_alto){//check if we need to
                currentAltoNote ++;
                    if(activeAltoDurations[currentAltoNote] == NULL){
                        currentAltoNote=0;
                    }

                    //call playNote function

                    NoteDurationTimer->CCR[3] += (int) ((float)onebeatticks*activeAltoDurations[currentAltoNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
                    playFrequency(Alto, activeAltoNotes[currentAltoNote]);
                    SpeakerPort->DIR |= (Alto);//make Alto output

                    insert_rest_alto = 1;
                }
                else{
                    SpeakerPort->DIR &= ~(Alto); //speaker to input mode
                    NoteDurationTimer->CCR[3] += NoteSeparatorTicks;
                    insert_rest_alto = 0;
                }

    }

    //Tenor
    if(TenInt){
        NoteDurationTimer->CCTL[2] &= ~TIMER_A_CCTLN_CCIFG;

        if(!insert_rest_tenor){//check if we need to
                        currentTenorNote ++;
                            if(activeTenorDurations[currentTenorNote] == NULL){
                                currentTenorNote=0;
                            }

                            //call playNote function

                            NoteDurationTimer->CCR[2] += (int) ((float)onebeatticks*activeTenorDurations[currentTenorNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
                            playFrequency(Tenor, activeTenorNotes[currentTenorNote]);
                            SpeakerPort->DIR |= (Tenor);//make Tenor output

                            insert_rest_tenor = 1;
                        }
                        else{
                            SpeakerPort->DIR &= ~(Tenor); //speaker to input mode
                            NoteDurationTimer->CCR[2] += NoteSeparatorTicks;
                            insert_rest_tenor = 0;
                        }

    }

    //Bass
    if(BasInt){
        NoteDurationTimer->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;

        if(!insert_rest_bass){//check if we need to
                                currentBassNote ++;
                                    if(activeBassDurations[currentBassNote] == NULL){
                                        currentBassNote=0;
                                    }

                                    //call playNote function

                                    NoteDurationTimer->CCR[1] += (int) ((float)onebeatticks*activeBassDurations[currentBassNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
                                    playFrequency(Bass, activeBassNotes[currentBassNote]);
                                    SpeakerPort->DIR |= (Bass);//make Bass output

                                    insert_rest_bass = 1;
                                }
                                else{
                                    SpeakerPort->DIR &= ~(Bass); //speaker to input mode
                                    NoteDurationTimer->CCR[1] += NoteSeparatorTicks;
                                    insert_rest_bass = 0;
                                }

    }

}
