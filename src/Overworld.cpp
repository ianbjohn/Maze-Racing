#include <iostream>
#include "Game.h"
#include "Hole.h"
#include "OverworldData.h"
#include "Overworld.h"

Overworld::Overworld()
{
    returnHoleIndex = 0;
}

Hole* Overworld::getHole(int i)
{
    return &holes[i];
}

int Overworld::getReturnHoleIndex()
{
    return returnHoleIndex;
}

//Make one of these for the level too if things besides just the screen tiles need to be loaded
void Overworld::load()
{
    Screen::loadNewScreen(2048, 2048, overworldData);

    //load the holes
    for (int i = 0; i < NUM_HOLES; i++)
        holes[i].setPosition(holeXs[i], holeYs[i]);

    //move the camera to the ship's starting point
    Game::camera.follow(Game::overworldShip, Game::overworld);
}

void Overworld::tick()
{
    for (int i = 0; i < NUM_HOLES; i++)
        holes[i].tick();
}

void Overworld::drawScreen(sf::RenderWindow& w)
{
    Screen::drawScreen(w);

    for (int i = 0; i < NUM_HOLES; i++)
        holes[i].draw(w);
}

Overworld::~Overworld()
{
    //dtor
}
