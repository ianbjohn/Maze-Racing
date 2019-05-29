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
    if (texture.loadFromFile("gfx/levelship.png") == 0)
        std::cerr << "Error loading ship sprite" << std::endl;
    rect.setTexture(&texture);
}

void OverworldShip::tick()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        y--;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        y++;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        x--;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        x++;

    //std::cout << x << ", " << y << std::endl;
    rect.setPosition(sf::Vector2f(x, y));
}

OverworldShip::~OverworldShip()
{
    //dtor
}
