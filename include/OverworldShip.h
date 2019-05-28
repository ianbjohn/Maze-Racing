#ifndef OVERWORLDSHIP_H
#define OVERWORLDSHIP_H
#include "Entity.h"


class OverworldShip : public Entity
{
    public:
        OverworldShip();
        virtual ~OverworldShip();

        void tick();

    private:
};

#endif // OVERWORLDSHIP_H
