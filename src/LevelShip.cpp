#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Screen.h"
#include "LevelShip.h"

LevelShip::LevelShip()
{
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
    if (texture.loadFromFile("gfx/levelship.png") == 0)
        std::cerr << "Error loading ship sprite" << std::endl;
    rect.setTexture(&texture);
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

        if (checkBackgroundCollision(Game::level) == 1) {
            state = STATE_DEAD;
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
    case STATE_DEAD:
        break;
    }

    rect.setPosition(sf::Vector2f(x, y));
}

LevelShip::~LevelShip()
{
    //dtor
}
