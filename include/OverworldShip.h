#ifndef OVERWORLDSHIP_H
#define OVERWORLDSHIP_H
#include "Entity.h"


class OverworldShip : public Entity
{
public:
    OverworldShip();
    virtual ~OverworldShip();

    int getReturnX();
    int getReturnY();

    void setReturnPosition(int x, int y);

    enum states{STATE_STILL, STATE_MOVING, STATE_EXPLODING};

    void tick();

private:
    //where in the spritesheet to draw the ship based on its direction
    //don't do this for every project, but the overworld ship is basic enough that I don't feel bad hardcoding this
    const int dirRectsX[4] = {0, 32, 64, 96};
    int returnX, returnY;
};

#endif // OVERWORLDSHIP_H
