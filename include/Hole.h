#ifndef HOLE_H
#define HOLE_H

#include "Entity.h"


class Hole : public Entity
{
public:
    Hole();
    virtual ~Hole();

    enum states{STATE_OPEN, STATE_COVERED};

    void tick();
};

#endif // HOLE_H
