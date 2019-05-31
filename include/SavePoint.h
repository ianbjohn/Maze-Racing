#ifndef SAVEPOINT_H
#define SAVEPOINT_H

#include "Entity.h"


class SavePoint : public Entity
{
public:
    SavePoint();
    virtual ~SavePoint();

    void tick();
};

#endif // SAVEPOINT_H
