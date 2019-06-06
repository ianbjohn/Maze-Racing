#include <iostream>
#include "Game.h"
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

void Overworld::setReturnIndex(int i)
{
    returnHoleIndex = i;
}

//Make one of these for the level too if things besides just the screen tiles need to be loaded
void Overworld::load()
{
    Screen::loadNewScreen(2048, 2048, overworldData);

    //load the save points
    for (int i = 0; i < NUM_SAVEPOINTS; i++)
        savePoints[i].setPosition(savePointXs[i], savePointYs[i]);

    //load the holes
    for (int i = 0; i < NUM_HOLES; i++) {
        holes[i].setPosition(holeXs[i], holeYs[i]);
        if (i < Game::getLevelNum())
            holes[i].setState(Hole::STATE_COVERED);
    }

    //arrow sign's X and Y are already set in its constructor
    //tutorial hole's X and Y are already set in its constructor

    //move the camera to the ship's starting point
    Game::camera.follow(Game::overworldShip, Game::overworld);
}

void Overworld::tick()
{
    for (Hole& h : holes)
        h.tick();

    for (SavePoint& s : savePoints)
        s.tick();

    tutorialHole.tick();
}

void Overworld::drawScreen(sf::RenderWindow& w)
{
    Screen::drawScreen(w);

    for (Hole& h : holes)
        h.draw(w);

    for (SavePoint& s : savePoints)
        s.draw(w);

    arrowSign.draw(w);
    tutorialHole.draw(w);
}

Overworld::~Overworld()
{
    //dtor
}
