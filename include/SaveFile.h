#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <sys/stat.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "OverworldData.h"

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
    bool newFile;

    //save file data
    int level;

    sf::RectangleShape rect;
    sf::Text text;
};

#endif // SAVEFILE_H
