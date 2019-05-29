#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
//#include "Game.h"

class Screen
{
public:
    Screen();
    virtual ~Screen();

    void loadNewScreen(int w, int h, const unsigned char* tileDataSource);
    int getScreenTile(int x, int y);
    void drawScreen(sf::RenderWindow& w);
    void cleanUpScreen();

    float shipStartX, shipStartY, portalX, portalY;
    int width, height, widthTiles, heightTiles;

protected:
    unsigned char** screenTiles;
    sf::RectangleShape** screenRects;
};

#endif // SCREEN_H
