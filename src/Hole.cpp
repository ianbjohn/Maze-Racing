#include "Game.h"
#include "Hole.h"

Hole::Hole()
{
    width = 32;
    height = 32;
    rect.setSize(sf::Vector2f(width, height));
    rect.setTexture(&Game::resourceManager.holeTexture);
}

void Hole::tick()
{
    switch (state) {
    case STATE_OPEN:
        if (Game::overworldShip.getState() != OverworldShip::STATE_EXPLODING && checkEntityCollision(Game::overworldShip) == 1) {
            Game::setState(Game::STATE_LEVEL);
            Game::levelShip.setPosition(96, 96);
            Game::levelShip.setState(LevelShip::STATE_MOVING);
            Game::levelShip.setDir(LevelShip::DIR_RIGHT);
        }
        rect.setTexture(&Game::resourceManager.holeTexture);
        break;
    case STATE_COVERED:
        rect.setTexture(&Game::resourceManager.coveredHoleTexture);
        break;
    }

    rect.setPosition(x, y);
}

Hole::~Hole()
{
    //dtor
}
