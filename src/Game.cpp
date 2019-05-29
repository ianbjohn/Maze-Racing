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
Overworld* Game::overworld;
Level* Game::level;
Camera* Game::camera;
LevelShip* Game::levelShip;
OverworldShip* Game::overworldShip;
sf::RenderWindow* Game::window;
sf::Event Game::event;

Game::Game()
{
    state = STATE_OVERWORLD;    //change to TITLE later of course
    stateOld = state;
    levelNum = 0;
    levelNumOld = 0;

    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racing");
    window->setFramerateLimit(60);

    level = new Level();
    overworld = new Overworld();
    camera = new Camera();
    levelShip = new LevelShip();
    overworldShip = new OverworldShip();
    level->loadNewLevel(0);
    overworld->load();
}

void Game::run()
{
    //once more comfortable with function pointers, have an array of pointers to each state function
    //like an indirect jump table
    //just to get rid of some of these parentheses
    while (Game::window->isOpen()) {
        while (Game::window->pollEvent(Game::event)) {
            if (Game::event.type == sf::Event::Closed)
                Game::window->close();

        }

        window->clear(sf::Color::White);

        //maybe in future projects have the entity list just in the game class? and draw whichever entities are currently active
        switch (state) {
        case STATE_OVERWORLD:
            Game::overworldShip->tick();
            Game::camera->follow(Game::overworldShip, Game::overworld);
            Game::overworld->drawScreen(window);
            Game::overworldShip->draw(window);

            //if the ship hit a hole, go to the level

            break;
        case STATE_LEVEL:
            Game::levelShip->tick();
            Game::camera->follow(Game::levelShip, Game::level);
            Game::level->drawScreen(window);
            Game::levelShip->draw(window);

            if (Game::levelShip->getState() == LevelShip::STATE_EXPLODING)
                state = STATE_OVERWORLD;
            else if (Game::getLevelNum() != Game::getOldLevelNum()) {
                //load new level if the player finished the current level
                Game::updateOldLevelNum();
                Game::level->cleanUpScreen();
                Game::level->loadNewLevel(Game::getLevelNum());
                state = STATE_OVERWORLD;
            }

            break;
        }

        Game::camera->draw(Game::window);
        Game::window->display();
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
