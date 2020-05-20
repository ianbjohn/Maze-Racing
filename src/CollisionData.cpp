#include "CollisionData.h"

//Collision data, sorted by entity ID, then by direction
const unsigned int** entityHitboxes[6] = {overworldShipHitboxes, levelShipHitboxes, arrowSignHitboxes, holeHitboxes, savePointHitboxes, tutorialHoleHitboxes};


const unsigned int* overworldShipHitboxes[4] = {overworldShipHitboxU, overworldShipHitboxD, overworldShipHitboxL, overworldShipHitboxR};

const unsigned int overworldShipHitboxU[32] = {
	0b00000000000000011000000000000000,
	0b00000000000000011000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000000111100000000000000,
	0b00000000000001111110000000000000,
	0b00000000000001111110000000000000,
	0b00000000000011111111000000000000,
	0b00000000000011111111000000000000,
	0b00000000000111111111100000000000,
	0b00000000000111111111100000000000,
	0b00000000001111111111110000000000,
	0b00000000001111111111110000000000,
	0b00000000011111111111111000000000,
	0b00000000011111111111111000000000,
	0b00000000111111111111111100000000,
	0b00000000111111111111111100000000,
	0b00000001111111111111111110000000,
	0b00000001111111111111111110000000,
	0b00000011111111111111111111000000,
	0b00000011111111111111111111000000,
	0b00000111111111111111111111100000,
	0b00000111111111111111111111100000,
	0b00001111111111111111111111110000,
	0b00001111111111111111111111110000,
	0b00011111111111111111111111111000,
	0b00011111111111111111111111111000,
	0b00111111111111111111111111111100,
	0b00111111111111111111111111111100,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111};

const unsigned int overworldShipHitboxD[32] = {
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b00111111111111111111111111111100,
	0b00111111111111111111111111111100,
	0b00011111111111111111111111111000,
	0b00011111111111111111111111111000,
	0b00001111111111111111111111110000,
	0b00001111111111111111111111110000,
	0b00000111111111111111111111100000,
	0b00000111111111111111111111100000,
	0b00000011111111111111111111000000,
	0b00000011111111111111111111000000,
	0b00000001111111111111111110000000,
	0b00000001111111111111111110000000,
	0b00000000111111111111111100000000,
	0b00000000111111111111111100000000,
	0b00000000011111111111111000000000,
	0b00000000011111111111111000000000,
	0b00000000001111111111110000000000,
	0b00000000001111111111110000000000,
	0b00000000000111111111100000000000,
	0b00000000000111111111100000000000,
	0b00000000000011111111000000000000,
	0b00000000000011111111000000000000,
	0b00000000000001111110000000000000,
	0b00000000000001111110000000000000,
	0b00000000000000111100000000000000,
	0b00000000000000111100000000000000,
	0b00000000000000011000000000000000,
	0b00000000000000011000000000000000};

const unsigned int overworldShipHitboxL[32] = {
	0b11000000000000000000000000000000,
	0b11110000000000000000000000000000,
	0b11111100000000000000000000000000,
	0b11111111000000000000000000000000,
	0b11111111110000000000000000000000,
	0b11111111111100000000000000000000,
	0b11111111111111000000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111111100000000000000,
	0b11111111111111111111000000000000,
	0b11111111111111111111110000000000,
	0b11111111111111111111111100000000,
	0b11111111111111111111111111000000,
	0b11111111111111111111111111110000,
	0b11111111111111111111111111111100,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111100,
	0b11111111111111111111111111110000,
	0b11111111111111111111111111000000,
	0b11111111111111111111111100000000,
	0b11111111111111111111110000000000,
	0b11111111111111111111000000000000,
	0b11111111111111111100000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111000000000000000000,
	0b11111111111100000000000000000000,
	0b11111111110000000000000000000000,
	0b11111111000000000000000000000000,
	0b11111100000000000000000000000000,
	0b11110000000000000000000000000000,
	0b11000000000000000000000000000000};

const unsigned int overworldShipHitboxR[32] = {
	0b00000000000000000000000000000011,
	0b00000000000000000000000000001111,
	0b00000000000000000000000000111111,
	0b00000000000000000000000011111111,
	0b00000000000000000000001111111111,
	0b00000000000000000000111111111111,
	0b00000000000000000011111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000111111111111111111,
	0b00000000000011111111111111111111,
	0b00000000001111111111111111111111,
	0b00000000111111111111111111111111,
	0b00000011111111111111111111111111,
	0b00001111111111111111111111111111,
	0b00111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b00111111111111111111111111111111,
	0b00001111111111111111111111111111,
	0b00000011111111111111111111111111,
	0b00000000111111111111111111111111,
	0b00000000001111111111111111111111,
	0b00000000000011111111111111111111,
	0b00000000000000111111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000000011111111111111,
	0b00000000000000000000111111111111,
	0b00000000000000000000001111111111,
	0b00000000000000000000000011111111,
	0b00000000000000000000000000111111,
	0b00000000000000000000000000001111,
	0b00000000000000000000000000000011};


const unsigned int* arrowSignHitboxes[4] = {arrowSignHitbox, arrowSignHitbox, arrowSignHitbox, arrowSignHitbox};

const unsigned int arrowSignHitbox[32] = {
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000};


const unsigned int* levelShipHitboxes[4] = {levelShipHitbox, levelShipHitbox, levelShipHitbox, levelShipHitbox};

const unsigned int levelShipHitbox[32] = {
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b11111100000000000000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111111111111111000000,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111000000,
	0b11111111111111110000000000000000,
	0b11111100000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000};


//Some entities share the same hitboxes, so they can be added by address instead of re-defined
const unsigned int* holeHitboxes[4] = {blockHitbox, blockHitbox, blockHitbox, blockHitbox};


const unsigned int* savePointHitboxes[4] = {overworldShipHitboxU, overworldShipHitboxU, overworldShipHitboxU, overworldShipHitboxU};


const unsigned int* tutorialHoleHitboxes[4] = {blockHitbox, blockHitbox, blockHitbox, blockHitbox};



//The wall block is technically not an entity, but we can specify its collision data (All solid pixels) here, since it's hard-coded to be passed into the background collision check routine
const unsigned int blockHitbox[32] = {
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111};