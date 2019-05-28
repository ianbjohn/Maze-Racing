#ifndef LEVELSHIP_H
#define LEVELSHIP_H
#include "Entity.h"
#define STARTING_SPEED 4
#define MOVING_SPEED .785 * STARTING_SPEED

class LevelShip : public Entity
{
public:
    LevelShip();
    virtual ~LevelShip();

    void tick();

    enum states {STATE_MOVING, STATE_DEAD};

private:
    float speed;
};

#endif // LEVELSHIP_H
