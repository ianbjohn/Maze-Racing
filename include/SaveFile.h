#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "Game.h"

#define WIDTH 600
#define HEIGHT 80

class SaveFile
{
public:
    SaveFile(int x, int y, int index);
    virtual ~SaveFile();

    int getX();
    int getY();
    int getIndex();

    void tick();    void draw(sf::RenderWindow& w);

private:
    int x, y, index;
    sf::RectangleShape rect;
};

#endif // SAVEFILE_H
