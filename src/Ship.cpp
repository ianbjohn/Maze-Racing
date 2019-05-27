#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Screen.h"
#include "Ship.h"

Ship::Ship(float x, float y)
{
    this->x = x;
    this->y = y;
    dir = 0;
    state = STATE_STILL;
    //manually set the hitbox size for now
    width = 20;
    height = 20;
    rect.setPosition(sf::Vector2f(this->x, this->y));
    rect.setSize(sf::Vector2f(width, height));
    if (texture.loadFromFile("gfx/ship.png") == 0)
        std::cerr << "Error loading ship sprite" << std::endl;
    rect.setTexture(&texture);
}

int Ship::getState()
{
    return state;
}

float Ship::getX()
{
    return x;
}

float Ship::getY()
{
    return y;
}

void Ship::setState(int state)
{
    this->state = state;
}

void Ship::setPosition(sf::Vector2f v)
{
    x = v.x;
    y = v.y;
}

void Ship::tick()
{
    switch (state)
    {
    case STATE_STILL:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            state = STATE_MOVING;
            dir = DIR_DOWN;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            state = STATE_MOVING;
            dir = DIR_UP;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            state = STATE_MOVING;
            dir = DIR_RIGHT;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            state = STATE_MOVING;
            dir = DIR_LEFT;
        }
        break;
    case STATE_MOVING:
        switch (dir) {
        case DIR_UP:
            y -= SPEED;
            break;
        case DIR_DOWN:
            y += SPEED;
            break;
        case DIR_LEFT:
            x -= SPEED;
            break;
        case DIR_RIGHT:
            x += SPEED;
            break;
        }

        if (checkBackgroundCollision() == 1) {
            state = STATE_DEAD;
            break;
        }

        if (checkPortalCollision() == 1) {
            Game::setLevel((Game::getLevel() + 1) % NUM_LEVELS);
            break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            dir = DIR_DOWN;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            dir = DIR_UP;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            dir = DIR_RIGHT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            dir = DIR_LEFT;
        break;
    case STATE_DEAD:
        break;
    }

    rect.setPosition(sf::Vector2f(x, y));
}

int Ship::checkBackgroundCollision()
{
    //rudimentary 4-corner collision checking / ejecting
    //once more diverse entity types are created in future projects, approach differently
    int tile = Game::screen->getScreenTile(x / 32, y / 32);
    if (tile == 1) return 1;
    tile = Game::screen->getScreenTile((x + width) / 32, y / 32);
    if (tile == 1) return 1;
    tile = Game::screen->getScreenTile(x / 32, (y + height) / 32);
    if (tile == 1) return 1;
    tile = Game::screen->getScreenTile((x + width) / 32, (y + height) / 32);
    if (tile == 1) return 1;

    return 0;
}

int Ship::checkPortalCollision()
{
    //I imagine a general entity collision function with an entity pointer wouldn't be much harder
    //somewhat similar to background collision, check each side of the hitbox to see if its outside the portal's hitbox, and if all of them fail, there was a collision
    //again, if entities in later games have different hitbox shapes, use a different approach
    if (x >= (Game::portal->getX() + Game::portal->getWidth())) return 0;
    if ((x + width) < (Game::portal->getX())) return 0;
    if (y >= (Game::portal->getY() + Game::portal->getHeight())) return 0;
    if ((y + height) < (Game::portal->getY())) return 0;

    return 1;
}

void Ship::draw(sf::RenderWindow& w)
{
    w.draw(rect);
}

Ship::~Ship()
{
    //dtor
}
