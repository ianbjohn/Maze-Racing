#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Screen.h"
#include "OverworldData.h"
#include "CollisionData.h"
#include "LevelShip.h"

LevelShip::LevelShip()
{
    ent_id = 1;
    x = 0;
    y = 0;
    dir = DIR_RIGHT;    //ship always moves right, but starts out not moving up or down. Direction will then change accordingly
    state = STATE_MOVING;
    speed = STARTING_SPEED;
    //manually set the hitbox size for now
    width = 32;
    height = 9;
    rect.setPosition(sf::Vector2f(this->x, this->y));
    rect.setSize(sf::Vector2f(width, height));
    rect.setTexture(&Game::resourceManager.levelShipTexture);
}

void LevelShip::tick()
{
    switch (state)
    {
    case STATE_MOVING:
        x += speed;
        switch (dir) {
        case DIR_UP:
            y -= speed;
            break;
        case DIR_DOWN:
            y += speed;
            break;
        }

        //if player finished level, load the next level, set new overworld ship position
        if (x + width >= Game::level.getWidth()) {
            //v-- probably not best practice to hard-code this stuff, but we have like 5 songs so I think its OK
            Game::resourceManager.mainSong.stop();

            Game::overworldShip.setPosition(holeNextShipXs[Game::getLevelNum()], holeNextShipYs[Game::getLevelNum()]);
            Game::overworld.getHole(Game::getLevelNum())->setState(Hole::STATE_COVERED);
            Game::setLevelNum(Game::getLevelNum() + 1);
            Game::level.cleanUpScreen();
            Game::level.load();
        }

        if (checkBackgroundCollision(Game::level) == 1) {
            state = STATE_EXPLODING;
            Game::resourceManager.mainSong.stop();
            break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            dir = DIR_DOWN;
            speed = MOVING_SPEED;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            dir = DIR_UP;
            speed = MOVING_SPEED;
        }
        break;
    case STATE_EXPLODING:
        break;
    }

    rect.setPosition(sf::Vector2f(x, y));
}

LevelShip::~LevelShip()
{
    //dtor
}
