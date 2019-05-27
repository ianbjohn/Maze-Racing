#ifndef SCREENDATA_H_INCLUDED
#define SCREENDATA_H_INCLUDED
#include "Game.h"

#define NUM_LEVELS 2

//structure of arrays :)
struct ScreenData
{
    float shipStartX[NUM_LEVELS];
    float shipStartY[NUM_LEVELS];
    float portalX[NUM_LEVELS];
    float portalY[NUM_LEVELS];
    const unsigned char* tiles[NUM_LEVELS];
};

extern const struct ScreenData screens;

extern const unsigned char screen0[106];
extern const unsigned char screen1[118];



#endif // SCREENDATA_H_INCLUDED
