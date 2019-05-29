#include <iostream>
#include "Game.h"
#include "OverworldData.h"
#include "Overworld.h"

Overworld::Overworld()
{

}

void Overworld::load()
{
    Screen::loadNewScreen(2048, 2048, overworldData);

    //move the ship to its starting position
    Game::overworldShip->setPosition(480, 1952);
    Game::overworldShip->setState(OverworldShip::STATE_STILL);
    Game::overworldShip->setDir(Entity::DIR_UP);

    //move the camera to the ship's starting point
    Game::camera->follow(Game::overworldShip, Game::overworld);
    std::cout << Game::camera->getX() << ", " << Game::camera->getY() << std::endl;
}

Overworld::~Overworld()
{
    //dtor
}
