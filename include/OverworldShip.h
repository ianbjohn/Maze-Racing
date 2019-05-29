#ifndef OVERWORLDSHIP_H
#define OVERWORLDSHIP_H
#include "Entity.h"


class OverworldShip : public Entity
{
public:
    OverworldShip();
    virtual ~OverworldShip();

    enum states{STATE_STILL, STATE_MOVING, STATE_EXPLODING};

    void tick();

private:
    //where in the spritesheet to draw the ship based on its direction
    //don't do this for everything, but the overworld ship is basic enough that I don't feel bad hardcoding this
    const int dirRectsX[4] = {0, 32, 64, 96};
};

#endif // OVERWORLDSHIP_H
