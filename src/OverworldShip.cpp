#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Screen.h"
#include "CollisionData.h"
#include "OverworldShip.h"

OverworldShip::OverworldShip()
{
    x = 480;
    y = 1952;
    returnX = x;
    returnY = y;
    dir = DIR_UP;
    state = STATE_STILL;

    width = 32;
    height = 32;
    rect.setPosition(sf::Vector2f(this->x, this->y));
    rect.setSize(sf::Vector2f(width, height));
    rect.setTexture(&Game::resourceManager.overworldShipTexture);
    rect.setTextureRect(sf::IntRect(dirRectsX[dir], 0, 32, 32));
}

int OverworldShip::getReturnX()
{
    return returnX;
}

int OverworldShip::getReturnY()
{
    return returnY;
}

void OverworldShip::setReturnPosition(int x, int y)
{
    returnX = x;
    returnY = y;
}

void OverworldShip::tick()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        y--;
        dir = DIR_UP;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        y++;
        dir = DIR_DOWN;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        x--;
        dir = DIR_LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        x++;
        dir = DIR_RIGHT;
    }

    if (checkBackgroundCollision(Game::overworld) == 1)
        state = STATE_EXPLODING;

    rect.setPosition(x, y);
    rect.setTextureRect(sf::IntRect(dirRectsX[dir], 0, 32, 32));
}

OverworldShip::~OverworldShip()
{
    //dtor
}
