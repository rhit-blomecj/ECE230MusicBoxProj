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

float BelleSopranoNote[] =
{
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,

                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        NULL};

float BelleSopranoDur[] =
{
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4, //belle mama belle ma ma ey
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4, //belle mama belle ma ma ey
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, //belle mama, belle mama, belle mama, belle mama,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4, //belle mama belle mama ey

                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        NULL};

float BelleAltoNote[] =
{
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,

                        R, R, R, R, R, R, R, R,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        R, R, R, R, R, R, R, R,
                        R, R, R, R, R, R, R, R,
                        NULL};

float BelleAltoDur[] =
{
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,

                        1, 1, 1, 1, 1, 1, 1, 1,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        NULL};

float BelleTenorNote[] =
{
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,

                        R, R, R, R, R, R, R, R,
                        R, R, R, R, R, R, R, R,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        R, R, R, R, R, R, R, R,
                        NULL};

float BelleTenorDur[] =
{
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,

                        1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        NULL};

float BelleBassNote[] =
{
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,

                        R, R, R, R, R, R, R, R,
                        R, R, R, R, R, R, R, R,
                        R, R, R, R, R, R, R, R,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        E4, E4, E4, E4, F4, E4, D4, G4, G4,
                        G4, G4, G4, G4, F4, F4, F4, F4, E4, E4, E4, E4, D4, D4, D4, D4,
                        C4, C4, C4, C4, D4, D4, C4, B3, C4,
                        NULL};

float BelleBassDur[] =
{
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,

                        1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75,
                        0.5, 0.25, 0.5, 0.75, 0.5, 0.25, 0.5, 0.75, 4,
                        NULL};

Song BelleMama;

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

    BelleMama.Title = "Belle Mama";
    BelleMama.Artist = "Think Cre8tive";
    BelleMama.bpm =  70;
    BelleMama.SopranoNotes = BelleSopranoNote;
    BelleMama.SopranoDurations = BelleSopranoDur;
    BelleMama.AltoNotes = BelleAltoNote;
    BelleMama.AltoDurations =  BelleAltoDur;
    BelleMama.TenorNotes = BelleTenorNote;
    BelleMama.TenorDurations = BelleTenorDur;
    BelleMama.BassNotes = BelleBassNote;
    BelleMama.BassDurations = BelleBassDur;


    Song Songs[] = {BelleMama, CarolOfTheBells, NULLSONG};//TO DETECT NULLSONG just check if (Title == NULL) if yes then set activesongindex to 0
    return Songs;
}
