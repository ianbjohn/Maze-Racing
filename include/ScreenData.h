#ifndef SCREENDATA_H_INCLUDED
#define SCREENDATA_H_INCLUDED
#include <string>

//figure out a better way to organize this
//perhaps a struct with the player's starting position, and a pointer to the compressed level data

extern const unsigned char screen0[106];
extern const unsigned char screen1[118];

extern const unsigned char* screens[2];


#endif // SCREENDATA_H_INCLUDED
