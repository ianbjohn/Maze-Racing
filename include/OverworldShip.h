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
};

#endif // OVERWORLDSHIP_H
