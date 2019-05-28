#include <iostream>
#include "Game.h"
#include "Level.h"


Level::Level()
{
    //ctor
}

void Level::loadNewLevel(int levelIndex)
{
    //get the ship and portal position
    width = levels.width[levelIndex];
    height = SCREEN_HEIGHT;
    widthTiles = width / 32;
    heightTiles = SCREEN_HEIGHT_TILES;

    //allocate the map tiles and rects based on width and height, and fetch tile data
    screenTiles = new unsigned char*[heightTiles];
    for (int i = 0; i < heightTiles; i++)
        screenTiles[i] = new unsigned char[widthTiles];

    //give each rectangle a position and size
    screenRects = new sf::RectangleShape*[heightTiles];
    for (int i = 0; i < heightTiles; i++)
        screenRects[i] = new sf::RectangleShape[widthTiles];

    for (int i = 0; i < heightTiles; i++) {
        for (int j = 0; j < widthTiles; j++) {
            screenRects[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
            screenRects[i][j].setSize(sf::Vector2f(32, 32));
        }
    }

    //decompress the level data into the map
    RLEdecompress(levels.tiles[levelIndex], screenTiles, widthTiles, heightTiles);

    //map the right texture to each tile
    for (int i = 0; i < heightTiles; i++) {
        for (int j = 0; j < widthTiles; j++) {
            if (screenTiles[i][j] == 1)
                screenRects[i][j].setTexture(&blockTexture);
        }
    }

    //move the ship to its new starting point
    Game::levelShip->setPosition(sf::Vector2f(64, 250));
    Game::levelShip->setState(LevelShip::STATE_MOVING);

    //move the camera to the ship's starting point
    Game::camera->follow(Game::levelShip, Game::level);
}

Level::~Level()
{
    //dtor
}
