#ifndef OVERWORLD_H
#define OVERWORLD_H

#include "Hole.h"
#include "TutorialHole.h"
#include "SavePoint.h"
#include "ArrowSign.h"
#include "Screen.h"

#define NUM_HOLES 30
#define NUM_SAVEPOINTS 1

class Overworld : public Screen
{
public:
    Overworld();
    virtual ~Overworld();

    Hole* getHole(int i);
    int getReturnHoleIndex();

    void setReturnIndex(int i);

    void load();
    void tick();

    void drawScreen(sf::RenderWindow& w);

private:
    SavePoint savePoints[NUM_SAVEPOINTS];

    Hole holes[NUM_HOLES];
    int returnHoleIndex;   //the first hole that should be re-opened following the player dying

    TutorialHole tutorialHole;
    ArrowSign arrowSign;
};

#endif // OVERWORLD_H
