#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
#include "ScreenData.h"

class Screen
{
public:
    Screen();
    virtual ~Screen();

    void loadNewScreen(int screenIndex);
    int getScreenTile(int x, int y);
    void drawScreen(sf::RenderWindow& w);
    int shipStartX, shipStartY;


private:
    int screenTiles[19][25];
    sf::RectangleShape screenRects[19][25];
    sf::Texture blockTexture;
};

#endif // SCREEN_H
