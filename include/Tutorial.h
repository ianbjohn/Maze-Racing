#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "Game.h"

class Tutorial
{
public:
    Tutorial();
    virtual ~Tutorial();

    void tick();
    void draw(sf::RenderWindow& w);

private:
    //these should probably get allocated/deallocated.
    //Be better about this in the future
    sf::RectangleShape tutHole;
    sf::RectangleShape tutWall;
    sf::RectangleShape tutSave;

    sf::Text tutTextHole;
    sf::Text tutTextWall;
    sf::Text tutTextSave;
};

#endif // TUTORIAL_H
