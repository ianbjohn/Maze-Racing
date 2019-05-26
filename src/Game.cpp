#include "Game.h"

int Game::state;
int Game::stateOld;
int Game::level;
int Game::levelOld;

Game::Game()
{
    state = 0;
}

int Game::getState()
{
    return state;
}

int Game::getOldState()
{
    return stateOld;
}

int Game::getLevel()
{
    return level;
}

int Game::getOldLevel()
{
    return levelOld;
}

void Game::setState(int s)
{
    state = s;
}

void Game::setLevel(int l)
{
    level = l;
}

void Game::updateOldState()
{
    stateOld = state;
}

void Game::updateOldLevel()
{
    levelOld = level;
}

Game::~Game()
{
    //dtor
}
