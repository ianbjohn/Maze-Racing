#include "Game.h"
#include "Portal.h"
#include "Screen.h"

Screen::Screen()
{
    blockTexture.loadFromFile("gfx/block.png");

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 25; j++) {
            screenRects[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
            screenRects[i][j].setSize(sf::Vector2f(32, 32));
        }
    }
}

void Screen::loadNewScreen(int screenIndex)
{
    //get the ship and portal positions
    shipStartX = screens.shipStartX[screenIndex];
    shipStartY = screens.shipStartY[screenIndex];
    portalX = screens.portalX[screenIndex];
    portalY = screens.portalY[screenIndex];

    //decompress the screen data into the screen array, RLE style
    int decCounter = 0, comCounter = 0;
    while (decCounter < 475) {
        //expect whatever value is currently being read to be a run-length
        int runLength = screens.tiles[screenIndex][comCounter];

        //load that many of the next value into the screen array
        while (runLength > 0) {
            screenTiles[decCounter / 25][decCounter % 25] = screens.tiles[screenIndex][comCounter + 1];
            decCounter++;
            runLength--;
        }
        comCounter += 2;
    }

    //map the right texture to each tile
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 25; j++) {
            if (screenTiles[i][j] == 1)
                screenRects[i][j].setTexture(&blockTexture);
        }
    }

    //move the ship to its new starting point
    Game::ship->setPosition(sf::Vector2f(shipStartX, shipStartY));
    Game::ship->setState(Ship::STATE_STILL);

    //move portal to its new starting point
    Game::portal->setPosition(sf::Vector2f(portalX, portalY));
}

int Screen::getScreenTile(int x, int y)
{
    return screenTiles[y][x];
}

void Screen::drawScreen(sf::RenderWindow& w)
{
    //I don't think it's necessary to draw every single 32x32 pixel tile on the screen as a rectangle shape, but for now that's what we're doing
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 25; j++) {
            if (screenTiles[i][j] == 1)
                w.draw(screenRects[i][j]);
        }
    }
}

Screen::~Screen()
{
    //dtor
}
