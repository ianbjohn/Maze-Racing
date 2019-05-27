#include <iostream>
#include "Game.h"
#include "Portal.h"

Portal::Portal(float x, float y)
{
    this->x = x;
    this->y = y;

    //manually set the hitbox size for now
    width = 32;
    height = 32;
    rect.setPosition(sf::Vector2f(this->x, this->y));
    rect.setSize(sf::Vector2f(width, height));
    if (texture.loadFromFile("gfx/portal.png") == 0)
        std::cerr << "Error loading portal sprite" << std::endl;
    rect.setTexture(&texture);
}

void Portal::setPosition(sf::Vector2f v)
{
    x = v.x;
    y = v.y;
}

Portal::~Portal()
{
    //dtor
}
