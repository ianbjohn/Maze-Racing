#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "Hole.h"
#include "Screen.h"

#define NUM_HOLES 30


class Overworld : public Screen
{
public:
    Overworld();
    virtual ~Overworld();

    Hole* getHole(int i);

    void load();
    void tick();

    void drawScreen(sf::RenderWindow& w);

private:
    Hole holes[NUM_HOLES];
};

#endif // OVERWORLD_H
