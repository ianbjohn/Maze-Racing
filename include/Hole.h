#ifndef HOLE_H
#define HOLE_H

#include <Entity.h>


class Hole : public Entity
{
public:
    Hole();
    virtual ~Hole();

    void tick();

private:
};

#endif // HOLE_H