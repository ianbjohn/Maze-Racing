#ifndef LEVELSHIP_H
#define LEVELSHIP_H
#include "Entity.h"
#define STARTING_SPEED 2.6      //maybe make this a variable so the ship can get faster as the levels progress
#define MOVING_SPEED .785 * STARTING_SPEED      //move at a 45 degree angle

class LevelShip : public Entity
{
public:
    LevelShip();
    virtual ~LevelShip();

    void tick();

    enum states {STATE_MOVING, STATE_EXPLODING};

private:
    float speed;
};

#endif // LEVELSHIP_H
