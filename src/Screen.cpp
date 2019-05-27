#include "Game.h"
#include "Portal.h"
#include "Screen.h"

Screen::Screen()
{
    blockTexture.loadFromFile("gfx/block.png");

    //give each rectangle a position and size
    for (int i = 0; i < ROOM_HEIGHT_TILES; i++) {
        for (int j = 0; j < ROOM_WIDTH_TILES; j++) {
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
    while (decCounter < ROOM_WIDTH_TILES * ROOM_HEIGHT_TILES) {
        //expect whatever value is currently being read to be a run-length
        int runLength = screens.tiles[screenIndex][comCounter];

        //load that many of the next value into the screen array
        while (runLength > 0) {
            screenTiles[decCounter / ROOM_WIDTH_TILES][decCounter % ROOM_WIDTH_TILES] = screens.tiles[screenIndex][comCounter + 1];
            decCounter++;
            runLength--;
        }
        comCounter += 2;
    }

    //map the right texture to each tile
    for (int i = 0; i < ROOM_HEIGHT_TILES; i++) {
        for (int j = 0; j < ROOM_WIDTH_TILES; j++) {
            if (screenTiles[i][j] == 1)
                screenRects[i][j].setTexture(&blockTexture);
        }
    }

    //move the ship to its new starting point
    Game::ship->setPosition(sf::Vector2f(shipStartX, shipStartY));
    Game::ship->setState(Ship::STATE_STILL);

    //move portal to its new starting point
    Game::portal->setPosition(sf::Vector2f(portalX, portalY));

    //move the camera to the ship's starting point
    Game::camera->followShip();
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
