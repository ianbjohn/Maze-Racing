#include <iostream>
#include "Game.h"
#include "LevelData.h"
#include "Level.h"


Level::Level()
{
    //ctor
}

void Level::loadNewLevel(int levelIndex)
{
    Screen::loadNewScreen(levels.width[levelIndex], SCREEN_HEIGHT, levels.tiles[levelIndex]);

    //move the ship to its new starting point
    Game::levelShip.setPosition(96, 96);
    Game::levelShip.setState(LevelShip::STATE_MOVING);
    Game::levelShip.setDir(LevelShip::DIR_RIGHT);

    //move the camera to the ship's starting point
    Game::camera.follow(Game::levelShip, Game::level);
}

Level::~Level()
{
    //dtor
}
