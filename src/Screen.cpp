#include <iostream>
#include "Game.h"
#include "Screen.h"

Screen::Screen()
{

}

void Screen::loadNewScreen(int w, int h, const unsigned char* tileDataSource)
{
    width = w;
    height = h;
    widthTiles = width / 32;
    heightTiles = h / 32;

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

    //decompress the tile data array into the map RLE style
    int decCounter = 0, comCounter = 0;
    while (decCounter < widthTiles * heightTiles) {
        //expect whatever value is currently being read to be a run-length
        int runLength = tileDataSource[comCounter];

        //load that many of the next value into the  array
        while (runLength > 0) {
            screenTiles[decCounter / widthTiles][decCounter % widthTiles] = tileDataSource[comCounter + 1];
            decCounter++;
            runLength--;
        }
        comCounter += 2;
    }

    //map the right texture to each tile
    for (int i = 0; i < heightTiles; i++) {
        for (int j = 0; j < widthTiles; j++) {
            if (screenTiles[i][j] == 1)
                screenRects[i][j].setTexture(&Game::resourceManager.blockTexture);
        }
    }
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
    for (int i = Game::camera.getY() / 32; i < (Game::camera.getY() / 32) + SCREEN_HEIGHT_TILES; i++) {
        for (int j = Game::camera.getX() / 32; j < (Game::camera.getX() / 32) + SCREEN_WIDTH_TILES; j++) {
            if (screenTiles[i][j] == 1)
                w.draw(screenRects[i][j]);
        }
    }
}

Screen::~Screen()
{
    //dtor
}
