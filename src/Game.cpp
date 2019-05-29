#include <iostream>
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
ResourceManager Game::resourceManager;
Overworld Game::overworld;
Level Game::level;
Camera Game::camera;
LevelShip Game::levelShip;
OverworldShip Game::overworldShip;
sf::RenderWindow Game::window{sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racing"};
sf::Event Game::event;

Game::Game()
{
    state = STATE_OVERWORLD;    //change to TITLE later of course
    stateOld = state;
    levelNum = 0;
    levelNumOld = 0;

    window.setFramerateLimit(60);

    level.loadNewLevel(0);
    overworld.load();
}

void Game::run()
{
    //once more comfortable with function pointers, have an array of pointers to each state function
    //like an indirect jump table
    //just to get rid of some of these parentheses
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        //maybe in future projects have the entity list just in the game class? and draw whichever entities are currently active
        switch (state) {
        case STATE_OVERWORLD:
            overworldShip.tick();
            camera.follow(overworldShip, Game::overworld);
            overworld.drawScreen(window);
            overworldShip.draw(window);

            //if the ship hit a hole, go to the level

            break;
        case STATE_LEVEL:
            levelShip.tick();
            camera.follow(levelShip, level);
            level.drawScreen(window);
            levelShip.draw(window);

            if (levelShip.getState() == LevelShip::STATE_EXPLODING)
                state = STATE_OVERWORLD;
            else if (getLevelNum() != getOldLevelNum()) {
                //load new level if the player finished the current level
                updateOldLevelNum();
                level.cleanUpScreen();
                level.loadNewLevel(getLevelNum());
                state = STATE_OVERWORLD;
            }

            break;
        }

        camera.draw(window);
        window.display();
    }
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
