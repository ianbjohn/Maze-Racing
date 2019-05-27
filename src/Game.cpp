#include "Game.h"

int Game::state;
int Game::stateOld;
int Game::level;
int Game::levelOld;
Screen* Game::screen;
Ship* Game::ship;
Portal* Game::portal;

Game::Game()
{
    state = 0;
    stateOld = 0;
    level = 0;
    levelOld = 0;

    screen = new Screen();
    screen->loadNewScreen(0);
    ship = new Ship(screen->shipStartX, screen->shipStartY);
    portal = new Portal(screen->portalX, screen->portalY);
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
