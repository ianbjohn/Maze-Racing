#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
#include "ScreenData.h"

//maximum height/width a room can be
//later, make rooms able to be different sizes, but keep these as the maxes
#define ROOM_WIDTH 2048
#define ROOM_HEIGHT 2048
#define ROOM_WIDTH_TILES (ROOM_WIDTH / 32)
#define ROOM_HEIGHT_TILES (ROOM_HEIGHT / 32)

class Screen
{
public:
    Screen();
    virtual ~Screen();

    void loadNewScreen(int screenIndex);
    int getScreenTile(int x, int y);
    void drawScreen(sf::RenderWindow& w);
    float shipStartX, shipStartY, portalX, portalY;

private:
    int screenTiles[ROOM_HEIGHT_TILES][ROOM_WIDTH_TILES];
    sf::RectangleShape screenRects[ROOM_HEIGHT_TILES][ROOM_WIDTH_TILES];
    sf::Texture blockTexture;   //if different textures are going to be used for the screen, make a resource manager
};

#endif // SCREEN_H
