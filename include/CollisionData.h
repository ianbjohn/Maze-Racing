#ifndef COLLISIONDATA_H_INCLUDED
#define COLLISIONDATA_H_INCLUDED

//Maybe at some point try making this more private (Part of the entity class maybe?), but I'm not quite sure of the best way to pass static read-only data like this to a class or something
extern const unsigned int** entityHitboxes[2];

extern const unsigned int* overworldShipHitboxes[4];
extern const unsigned int overworldShipHitboxesU[32];
extern const unsigned int overworldShipHitboxesD[32];
extern const unsigned int overworldShipHitboxesL[32];
extern const unsigned int overworldShipHitboxesR[32];

extern const unsigned int* blockHitboxes[4];
extern const unsigned int blockHitbox[32];

#endif