#include <iostream>
#include "Game.h"
#include "Portal.h"
#include "Screen.h"

Screen::Screen()
{
    //move this to a ResourceManager
    blockTexture.loadFromFile("gfx/block.png");
}

void Screen::cleanUpScreen()
{
    //free the screen's memory
    for (int i = 0; i < heightTiles; i++) {
        delete screenTiles[i];
        delete screenRects[i];
    }
    delete screenTiles;
    delete screenRects;
}

int Screen::getScreenTile(int x, int y)
{
    return screenTiles[y][x];
}

void Screen::drawScreen(sf::RenderWindow& w)
{
    //only draw textures that are currently inside the camera
    for (int i = Game::camera->getY() / 32; i < (Game::camera->getY() / 32) + SCREEN_HEIGHT_TILES; i++) {
        for (int j = Game::camera->getX() / 32; j < (Game::camera->getX() / 32) + SCREEN_WIDTH_TILES; j++) {
            if (screenTiles[i][j] == 1)
                w.draw(screenRects[i][j]);
        }
    }
}

Screen::~Screen()
{
    //dtor
}
