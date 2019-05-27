#ifndef SCREENDATA_H_INCLUDED
#define SCREENDATA_H_INCLUDED
#include "Game.h"

#define NUM_LEVELS 3

//structure of arrays :)
struct ScreenData
{
    int width[NUM_LEVELS];
    int height[NUM_LEVELS];
    float shipStartX[NUM_LEVELS];
    float shipStartY[NUM_LEVELS];
    float portalX[NUM_LEVELS];
    float portalY[NUM_LEVELS];
    const unsigned char* tiles[NUM_LEVELS];
};

extern const struct ScreenData screens;

extern const unsigned char screen0[162];
extern const unsigned char screen1[290];
extern const unsigned char screen2[498];



#endif // SCREENDATA_H_INCLUDED
