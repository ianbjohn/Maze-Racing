#include "Game.h"
#include "TutorialHole.h"

TutorialHole::TutorialHole()
{
	ent_id = 5;
    x = 576;
    y = 1856;
    rect.setPosition(x, y);
}

void TutorialHole::tick()
{
    if (checkEntityCollision(Game::overworldShip) == true) {
        Game::overworldShip.setPosition(480, 1952);
        Game::overworldShip.setDir(Entity::DIR_UP);
        Game::setState(Game::STATE_TUTORIAL);
    }
}

TutorialHole::~TutorialHole()
{
    //dtor
}
