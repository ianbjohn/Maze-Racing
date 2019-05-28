#include "Screen.h"
#include "Entity.h"
#include "Level.h"
#include "Overworld.h"
#include "Camera.h"
#include "LevelShip.h"
#include "OverworldShip.h"
#include "Game.h"

int Game::state;
int Game::stateOld;
int Game::levelNum;
int Game::levelNumOld;
Overworld* Game::overworld;
Level* Game::level;
Camera* Game::camera;
LevelShip* Game::levelShip;
OverworldShip* Game::overworldShip;

Game::Game()
{
    state = 0;
    stateOld = 0;
    levelNum = 0;
    levelNumOld = 0;

    level = new Level();
    overworld = new Overworld();
    camera = new Camera();
    levelShip = new LevelShip();
    overworldShip = new OverworldShip();
    level->loadNewLevel(0);
    overworld->load();
}

int Game::getState()
{
    return state;
}

int Game::getOldState()
{
    return stateOld;
}

int Game::getLevelNum()
{
    return levelNum;
}

int Game::getOldLevelNum()
{
    return levelNumOld;
}

void Game::setState(int s)
{
    state = s;
}

void Game::setLevelNum(int l)
{
    levelNum = l;
}

void Game::updateOldState()
{
    stateOld = state;
}

void Game::updateOldLevelNum()
{
    levelNumOld = levelNum;
}

Game::~Game()
{
    //dtor
}
