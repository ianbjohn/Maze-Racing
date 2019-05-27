#include "ScreenData.h"

const struct ScreenData screens = {
    //ship start X
    {128, 512},
    //ship start Y
    {128, 64},
    //portal X
    {224, 416},
    //portal Y
    {960, 32},
    //pointers to tile data
    {screen0, screen1}
};

const unsigned char screen0[162] = {
    33,1,30,0,2,1,30,0,2,1,30,0,2,1,30,0,2,1,30,0,2,1,30,0,27,1,5,0,2,1,30,0,2,1,30,0,2,1,30,0,2,1,30,0,2,1,17,0,5,1,8,0,2,1,16,0,7,1,7,0,2,1,15,0,9,1,6,0,2,1,15,0,9,1,6,0,3,1,14,0,9,1,5,0,6,1,12,0,9,1,5,0,6,1,12,0,9,1,5,0,6,1,13,0,7,1,7,0,5,1,14,0,5,1,8,0,6,1,26,0,6,1,26,0,7,1,25,0,7,1,25,0,7,1,25,0,7,1,25,0,8,1,24,0,8,1,23,0,9,1,23,0,9,1,6,0,2,1,15,0,34,1};

const unsigned char screen1[290] = {
    33,1,13,0,1,1,3,0,15,1,13,0,1,1,3,0,15,1,13,0,1,1,3,0,15,1,13,0,1,1,3,0,7,1,4,0,4,1,4,0,5,1,4,0,1,1,3,0,6,1,6,0,3,1,4,0,5,1,4,0,1,1,3,0,6,1,7,0,2,1,4,0,5,1,4,0,1,1,3,0,6,1,7,0,2,1,4,0,5,1,4,0,1,1,3,0,6,1,7,0,2,1,4,0,5,1,4,0,1,1,3,0,6,1,2,0,2,1,3,0,2,1,4,0,5,1,3,0,1,1,5,0,5,1,2,0,2,1,3,0,2,1,4,0,5,1,3,0,1,1,12,0,2,1,3,0,2,1,12,0,1,1,12,0,2,1,3,0,2,1,12,0,1,1,12,0,2,1,3,0,2,1,3,0,3,1,7,0,1,1,11,0,2,1,3,0,2,1,3,0,3,1,8,0,11,1,5,0,2,1,3,0,3,1,24,0,2,1,13,0,5,1,12,0,2,1,30,0,2,1,8,0,3,1,19,0,2,1,8,0,3,1,9,0,5,1,5,0,4,1,6,0,3,1,19,0,4,1,28,0,5,1,9,0,6,1,12,0,6,1,26,0,6,1,25,0,8,1,20,0,13,1,15,0,18,1,7,0,113,1};
