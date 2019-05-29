#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Screen.h"
#include "OverworldShip.h"

OverworldShip::OverworldShip()
{
    x = 0;
    y = 0;
    dir = DIR_UP;
    state = STATE_STILL;

    width = 32;
    height = 32;
    rect.setPosition(sf::Vector2f(this->x, this->y));
    rect.setSize(sf::Vector2f(width, height));
    if (texture.loadFromFile("gfx/overworldship.png") == 0)
        std::cerr << "Error loading ship sprite" << std::endl;
    rect.setTexture(&texture);
    rect.setTextureRect(sf::IntRect(dirRectsX[dir], 0, 32, 32));
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

    rect.setPosition(x, y);
    rect.setTextureRect(sf::IntRect(dirRectsX[dir], 0, 32, 32));
}

OverworldShip::~OverworldShip()
{
    //dtor
}
