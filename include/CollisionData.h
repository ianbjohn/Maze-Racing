#ifndef COLLISIONDATA_H_INCLUDED
#define COLLISIONDATA_H_INCLUDED

//Maybe at some point try making this more private (Part of the entity class maybe?), but I'm not quite sure of the best way to pass static read-only data like this to a class or something
extern const unsigned int** entityHitboxes[6];

extern const unsigned int* overworldShipHitboxes[4];
extern const unsigned int overworldShipHitboxU[32];
extern const unsigned int overworldShipHitboxD[32];
extern const unsigned int overworldShipHitboxL[32];
extern const unsigned int overworldShipHitboxR[32];

extern const unsigned int* levelShipHitboxes[4];
extern const unsigned int levelShipHitbox[32];

extern const unsigned int* arrowSignHitboxes[4];
extern const unsigned int arrowSignHitbox[32];

extern const unsigned int* holeHitboxes[4];
extern const unsigned int* savePointHitboxes[4];
extern const unsigned int* tutorialHoleHitboxes[4];

extern const unsigned int blockHitbox[32];

#endif