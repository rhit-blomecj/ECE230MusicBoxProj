/*
 * songs.h
 *
 *  Created on: Feb 16, 2024
 *      Author: blomecj
 */

#ifndef SONGS_H_
#define SONGS_H_
#include "NoteDefs.h"
#include <stdio.h>  //NULL is defined in this header file
typedef struct _Song {
    char* Title;

    char* Artist;

    int bpm;

    float *SopranoNotes;
    float *SopranoDurations;

    float *AltoNotes;
    float *AltoDurations;

    float *TenorNotes;
    float *TenorDurations;

    float *BassNotes;
    float *BassDurations;

} Song;




extern Song* createSongsArray(void);


#endif /* SONGS_H_ */
