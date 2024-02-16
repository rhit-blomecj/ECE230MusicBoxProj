/*
 * main.h
 *
 *  Created on: Feb 4, 2024
 *      Author: blomecj
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "global.h"
#include "csLFXT.h"
#include "LCDDriver.h"
#include "SpeakerDriver.h"
#include "StepperDriver.h"
#include "SpeakerDriver.h"
#include "SwitchDriver.h"
#include <stdio.h>  //NULL is defined in this header file




#define Soprano Speaker4//
#define Alto Speaker3
#define Tenor Speaker2
#define Bass Speaker1


typedef enum _SwitchState {NotPressed, Pressed} SwitchState;
typedef enum _BoxState {Closed, Open} BoxState;//box enum

typedef struct {
    char* Title;

    char* Artist;

    int bpm;

    float *SopranoNotes[];
    float *SopranoDurations[];

    float *AltoNotes[];
    float *AltoDurations[];

    float *TenorNotes[];
    float *TenorDurations[];

    float *BassNotes[];
    float *BassDurations[];

} Song;

#endif /* MAIN_H_ */
