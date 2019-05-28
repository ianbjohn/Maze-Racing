#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
//#include "Game.h"

class Screen
{
public:
    Screen();
    virtual ~Screen();

    void loadNewScreen(int screenIndex);
    int getScreenTile(int x, int y);
    void drawScreen(sf::RenderWindow& w);
    void cleanUpScreen();

    float shipStartX, shipStartY, portalX, portalY;
    int width, height, widthTiles, heightTiles;

protected:
    int** screenTiles;
    sf::RectangleShape** screenRects;
    sf::Texture blockTexture;   //move to resource manager
};

#endif // SCREEN_H
