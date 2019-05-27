#include "Game.h"

int Game::state;
int Game::stateOld;
int Game::level;
int Game::levelOld;
Screen* Game::screen;
Camera* Game::camera;
Ship* Game::ship;
Portal* Game::portal;

Game::Game()
{
    state = 0;
    stateOld = 0;
    level = 0;
    levelOld = 0;

    screen = new Screen();
    camera = new Camera();
    ship = new Ship(0, 0);
    portal = new Portal(0, 0);
    screen->loadNewScreen(0);
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
