/*
 * songs.c
 *
 *  Created on: Feb 16, 2024
 *      Author: blomecj
 */

#include "songs.h"

float CarolSopranoNote[] = {
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,

                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,

                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,

                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,

                            D5, C5, D5, AS4,
                            D5, C5, D5, AS4,
                            D5, C5, D5, AS4,
                            D5, C5, D5, AS4,

                            G5, G5, G5, F5, DS5,
                            D5, D5, D5, C5, AS4,
                            C5, C5, C5, D5, C5,
                            G4, G4, G4, G4,

                            D4, E4, FS4, G4, A4, AS4,
                            C5, D5, C5, AS4,
                            D4, E4, FS4, G4, A4, AS4,
                            C5, D5, C5, AS4,

                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,
                            AS4, A4, AS4, G4,

                            G4,
                            G4,
                            G4,
                            G4,

                            D5, C5, D5, G4,
                            G4,
                            NULL};
float CarolSopranoDur[] = {
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,

                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,

                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,

                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,

                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,

                           1, 0.5, 0.5, 0.5, 0.5,
                           1, 0.5, 0.5, 0.5, 0.5,
                           1, 0.5, 0.5, 0.5, 0.5,
                           1, 0.5, 0.5, 1,

                           0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
                           0.5, 0.5, 1, 1,
                           0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
                           0.5, 0.5, 1, 1,

                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,
                           1, 0.5, 0.5, 1,

                           3, 3, 3, 3,

                           1, 0.5, 0.5, 1,
                           3,
                           NULL};
float CarolAltoNote[] = {
                         R,
                         R,
                         R,
                         R,

                         G4,
                         F4,
                         DS4,
                         D4,

                         G4,
                         F4,
                         DS4,
                         D4,

                         G4, G4, G4, G4,
                         G4, G4, G4, G4,
                         G4, G4, G4, G4,
                         G4, G4, G4, G4,

                         AS4, A4, AS4, G4,
                         AS4, A4, AS4, G4,
                         AS4, A4, AS4, G4,
                         AS4, A4, AS4, G4,

                         G4, G4, G4, G4,
                         G4, G4, G4, G4,
                         G4, G4, G4, G4,
                         G4, G4, G4, G4,

                         D4,
                         D4, FS4, G4,
                         D4,
                         D4, FS4, G4,

                         D4,
                         C4,
                         F4,
                         DS4,

                         D4,
                         D4,
                         D4,
                         D4,

                         AS4, A4, AS4, G4,
                         G4,
                         NULL};
float CarolAltoDur[] = {
                        3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        3,
                        3,

                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,

                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,

                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,

                        3,
                        1, 1, 1,
                        3,
                        1, 1, 1,

                        3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        3,
                        3,

                        1, 0.5, 0.5, 1,
                        3,

                        NULL};

float CarolTenorNote[] = {R,
                          R,
                          R,
                          R,

                          R,
                          R,
                          R,
                          R,

                          DS4,
                          D4,
                          C4,
                          G3,

                          C4, C4, C4, C4,
                          D4, D4, D4, D4,
                          DS4, DS4, DS4, DS4,
                          D4, D4, D4, D4,

                          D4,
                          E4,
                          F4, DS4, D4,
                          G4, F4, DS4, D4,

                          D4, DS4, DS4, D4, C4,
                          D4, D4, D4, D4,
                          DS4, DS4, DS4, F4, DS4,
                          D4, D4, D4, D4,

                          AS3, A3, AS3, G3,
                          AS3, A3, AS3, G3,
                          AS3, A3, AS3, G3,
                          AS3, A3, AS3, G3,

                          G3,
                          G3,
                          G3,
                          G3,

                          AS3, A3, AS3, G3,
                          AS3, A3, AS3, G3,
                          AS3, A3, AS3, G3,
                          AS3, A3, AS3, G3,

                          R,
                          R,
                          NULL};
float CarolTenorDur[] = {
                         3,
                         3,
                         3,
                         3,

                         3,
                         3,
                         3,
                         3,

                         3,
                         3,
                         3,
                         3,

                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,

                         3,
                         3,
                         1, 1, 1,
                         0.5, 0.5, 1, 1,

                         1, 0.5, 0.5, 0.5, 0.5,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 0.5, 0.5,
                         1, 0.5, 0.5, 1,

                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,

                         3,
                         3,
                         3,
                         3,

                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,
                         1, 0.5, 0.5, 1,

                         3,
                         3,

                         NULL};

float CarolBassNote[] = {
                         R,
                         R,
                         R,
                         R,

                         R,
                         R,
                         R,
                         R,

                         R,
                         R,
                         R,
                         R,

                         DS3, DS3, DS3, DS3,
                         G3, G3, G3, G3,
                         C4, C4, C4, C4,
                         G3, G3, G3, G3,

                         G3, G3, G3, G3,
                         G3, G3, G3, G3,
                         G3, G3, G3, G3,
                         G3, G3, G3, G3,

                         AS3, A3, AS3, G3,
                         AS3, A3, AS3, G3,
                         AS3, A3, AS3, G3,
                         AS3, A3, AS3, G3,

                         D3,
                         D3,
                         D3,
                         D3, E3,

                         F3,
                         DS3,
                         D3,
                         C3,

                         G2,
                         G2,
                         G2,
                         G2,

                         R,
                         G2,
                         NULL};
float CarolBassDur[] = {3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        3,
                        3,

                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,

                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,

                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,
                        1, 0.5, 0.5, 1,

                        3,
                        3,
                        3,
                        2, 1,

                        3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        3,
                        3,

                        3,
                        3,
                        NULL};
Song CarolOfTheBells;


Song NULLSONG ={NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL} ;

Song* createSongsArray(void){
    CarolOfTheBells.Title = "Carol Of The Bells";
    CarolOfTheBells.Artist = "M. Leontovich";
    CarolOfTheBells.bpm =  140;
    CarolOfTheBells.SopranoNotes = CarolSopranoNote;
    CarolOfTheBells.SopranoDurations = CarolSopranoDur;
    CarolOfTheBells.AltoNotes = CarolAltoNote;
    CarolOfTheBells.AltoDurations =  CarolAltoDur;
    CarolOfTheBells.TenorNotes = CarolTenorNote;
    CarolOfTheBells.TenorDurations = CarolTenorDur;
    CarolOfTheBells.BassNotes = CarolBassNote;
    CarolOfTheBells.BassDurations = CarolBassDur;


    Song Songs[] = {CarolOfTheBells, NULLSONG};//TO DETECT NULLSONG just check if (Title == NULL) if yes then set activesongindex to 0
    return Songs;
}
