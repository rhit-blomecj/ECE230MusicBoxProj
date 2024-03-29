

/**
 *
 * main.c
 */
#include "main.h"


int onebeatticks = 0;

SwitchState Switch1State = Pressed;

int currentSopranoNote = 0;
int currentAltoNote = 0;
int currentTenorNote = 0;
int currentBassNote = 0;

Song Songs[4];

int activeSongIndex = 0;

Song activeSong;

char insert_rest_soprano = 1;
char insert_rest_alto = 1;
char insert_rest_tenor = 1;
char insert_rest_bass = 1;





void SongPause(void){
    NoteDurationTimer->CTL &= ~(TIMER_A_CTL_MC_2 | TIMER_A_CTL_CLR);//set Duration timer to stop mode


    stopAllSpeakers();
}

void SongPlay(void){
    startAllSpeakers();

    NoteDurationTimer->CTL |= TIMER_A_CTL_MC_2;//set duration timer to Continuous

}

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

void displaySongAndArtistName(void){
    //START LCD COMMANDS
       lcd_clear();

       lcd_SetLineNumber(0x00);// first line addr
       lcd_puts(activeSong.Title);

       lcd_SetLineNumber(0x40);// second line addr
       lcd_puts(activeSong.Artist);
   //END LCD COMMANDS
}

void setBPM(void){
    //bpm->rpm 240=12 40 =2 so bpm/20 = rpm of stepperMotor
    onebeatticks = (int)((60.0/(float)activeSong.bpm)*(float)NoteDurationTimerFreq);

    setRPM(((float)activeSong.bpm/(float)bpmTorpmConst), Stepper1);
}

void setSongCCRs(void){

      playFrequency(Soprano, activeSong.SopranoNotes[currentSopranoNote]);
      playFrequency(Alto, activeSong.AltoNotes[currentAltoNote]);
      playFrequency(Tenor, activeSong.TenorNotes[currentTenorNote]);
      playFrequency(Bass, activeSong.BassNotes[currentBassNote]);

      NoteDurationTimer->CCR[4] += (int) (onebeatticks*activeSong.SopranoDurations[currentSopranoNote]);
      NoteDurationTimer->CCR[3] += (int) (onebeatticks*activeSong.AltoDurations[currentAltoNote]);
      NoteDurationTimer->CCR[2] += (int) (onebeatticks*activeSong.TenorDurations[currentTenorNote]);
      NoteDurationTimer->CCR[1] += (int) (onebeatticks*activeSong.BassDurations[currentBassNote]);
}

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

#ifdef VERIFICATION_H_
	initVerificationLEDs();
#endif

	//Speaker Setup START
	initSpeaker(SpeakerPort, Soprano);//call for all 4 speakers
	initSpeaker(SpeakerPort, Alto);
	initSpeaker(SpeakerPort, Tenor);
	initSpeaker(SpeakerPort, Bass);
	initSpeakerFreqTimer();
	//Speaker Setup END

	NoteDurationSetup();

	lcd8bits_init();

	//Stepper Setup START
	initStepperMotor(Stepper1_port, Stepper1);
	initStepperTimer();
	//Stepper Setup END


	__enable_irq();                 // Enable global interrupt


    //initializes songs array
	createSongsArray(Songs);



	//MagnetSwitchSetup
	SwitchInit(MagnetSwitchPort, MagnetSwitchPin);


	//Set active song
   activeSong = Songs[activeSongIndex];

   if(activeSong.Title == NULL){//we use a NULL song at the end of the array to check the end of the array
       activeSongIndex = 0;
       activeSong = Songs[activeSongIndex];//this assumes that there is at least one Not NULL song in the Songs array
   }

   //Set active notes to beginning of song
   currentSopranoNote = 0;
   currentAltoNote = 0;
   currentTenorNote = 0;
   currentBassNote = 0;

   //displays song name and artist to the LCD
   displaySongAndArtistName();

   //sets bpm and the values that are based on bpm (like rpm of Stepper)
   setBPM();

   //sets interrupt thresholds for both duration and calls playFrequency on active notes
   setSongCCRs();

	Switch1State = CheckSwitch(MagnetSwitchPort, MagnetSwitchPin);

	while(1){
	    if(Switch1State == Pressed){//these if statements should probably not be needed but I will keeep them because I think it makes it more explicit what state operations should occur in
	        //All Speaker Timers to Stop Mode including frequency stuff
	           SongPause();

	           disableStepperMotor(Stepper1_port, Stepper1);

	           activeSongIndex++;


	           //Set active song
	           activeSong = Songs[activeSongIndex];

	           if(activeSong.Title == NULL){
	               activeSongIndex = 0;
	               activeSong = Songs[activeSongIndex];//this assumes that there is at least one song in the Songs array
	           }

	           //Set active notes to beginning of song
	           currentSopranoNote = 0;
	           currentAltoNote = 0;
	           currentTenorNote = 0;
	           currentBassNote = 0;

	           //this is just setting this value so its consistant with how songs start (it adds the division between notes)
	           insert_rest_soprano = 1;
	           insert_rest_alto = 1;
	           insert_rest_tenor = 1;
	           insert_rest_bass = 1;

	           //displays song name and artist to the LCD
	           displaySongAndArtistName();

	           //sets bpm and the values that are based on bpm (like rpm of Stepper)
	           setBPM();

	           //sets interrupt thresholds for both duration and calls playFrequency on active notes
	           setSongCCRs();
	    }
	    SwitchDebounce();//debounce for after "press"/box close

	    while(Switch1State == Pressed){//check for state change
	        Switch1State = CheckSwitch(MagnetSwitchPort, MagnetSwitchPin);
	    }

	    if(Switch1State == NotPressed){
	        SongPlay();

           enableStepperMotor(Stepper1_port, Stepper1);
	    }
	    SwitchDebounce();//debounce for after "release"/box open

	    while(Switch1State == NotPressed){//check for state change
	                Switch1State = CheckSwitch(MagnetSwitchPort, MagnetSwitchPin);
        }

	}

}



//global initialization of this so they are static by default they are used primarily in the interrupt handler and are reset when song is switched in main
//currentNote defined above
//onebeatticks defined above
//insert_rest_soprano defined above
//insert_rest_alto
//insert_rest_tenor
//insert_rest_bass

void TA2_N_IRQHandler(void){
    char SopInt = NoteDurationTimer->CCTL[4] & TIMER_A_CCTLN_CCIFG;
    char AltInt = NoteDurationTimer->CCTL[3] & TIMER_A_CCTLN_CCIFG;
    char TenInt = NoteDurationTimer->CCTL[2] & TIMER_A_CCTLN_CCIFG;
    char BasInt = NoteDurationTimer->CCTL[1] & TIMER_A_CCTLN_CCIFG;
    //Soprano
    if(SopInt){
        NoteDurationTimer->CCTL[4] &= ~TIMER_A_CCTLN_CCIFG;//clear flag

#ifdef VERIFICATION_H_
        toggleRed();//allows verification of soprano note lengths
#endif


        if(!insert_rest_soprano){//check if we need to
            currentSopranoNote ++;
            if(activeSong.SopranoDurations[currentSopranoNote] == NULL){
                currentSopranoNote=0;
            }

            //call playNote function

            NoteDurationTimer->CCR[4] += (int) ((float)onebeatticks*activeSong.SopranoDurations[currentSopranoNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
            playFrequency(Soprano, activeSong.SopranoNotes[currentSopranoNote]);
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
                    if(activeSong.AltoDurations[currentAltoNote] == NULL){
                        currentAltoNote=0;
                    }

                    //call playNote function

                    NoteDurationTimer->CCR[3] += (int) ((float)onebeatticks*activeSong.AltoDurations[currentAltoNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
                    playFrequency(Alto, activeSong.AltoNotes[currentAltoNote]);
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
                            if(activeSong.TenorDurations[currentTenorNote] == NULL){
                                currentTenorNote=0;
                            }

                            //call playNote function

                            NoteDurationTimer->CCR[2] += (int) ((float)onebeatticks*activeSong.TenorDurations[currentTenorNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
                            playFrequency(Tenor, activeSong.TenorNotes[currentTenorNote]);
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
                                    if(activeSong.BassDurations[currentBassNote] == NULL){
                                        currentBassNote=0;
                                    }

                                    //call playNote function

                                    NoteDurationTimer->CCR[1] += (int) ((float)onebeatticks*activeSong.BassDurations[currentBassNote]);//will need to do this in ticks onebeat ticks needs to be calculated based on bpm
                                    playFrequency(Bass, activeSong.BassNotes[currentBassNote]);
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
