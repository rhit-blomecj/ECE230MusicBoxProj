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

    const float *SopranoNotes;
    const float *SopranoDurations;

    const float *AltoNotes;
    const float *AltoDurations;

    const float *TenorNotes;
    const float *TenorDurations;

    const float *BassNotes;
    const float *BassDurations;

} Song;




extern void createSongsArray(Song* Songs);


#endif /* SONGS_H_ */
