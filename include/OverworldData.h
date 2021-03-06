#ifndef OVERWORLDDATA_H_INCLUDED
#define OVERWORLDDATA_H_INCLUDED

#define NUM_HOLES 30
#define NUM_SAVEPOINTS 1

extern const unsigned char overworldData[666];

extern const int savePointXs[NUM_SAVEPOINTS];
extern const int savePointYs[NUM_SAVEPOINTS];

extern const int holeXs[NUM_HOLES];
extern const int holeYs[NUM_HOLES];
extern const int holeNextShipXs[NUM_HOLES];     //where on the overworld the ship should be after completing the corresponding level
extern const int holeNextShipYs[NUM_HOLES];

#endif // OVERWORLDDATA_H_INCLUDED
