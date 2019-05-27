#include "Game.h"
#include "Camera.h"

Camera::Camera()
{
    x = 0;
    y = 0;
    view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
}

float Camera::getX()
{
    return x;
}

float Camera::getY()
{
    return y;
}

void Camera::followShip()
{
    //put the ship in the center of the camera view, unless he's at one of the corners of the room
    if (Game::ship->getX() < SCREEN_WIDTH / 2)
        x = 0;
    else if (Game::ship->getX() >= Game::screen->width - 1 - (SCREEN_WIDTH / 2))
        x = Game::screen->width - SCREEN_WIDTH;
    else
        x = Game::ship->getX() - (SCREEN_WIDTH / 2);

    if (Game::ship->getY() < SCREEN_HEIGHT / 2)
        y = 0;
    else if (Game::ship->getY() >= Game::screen->height - 1 - (SCREEN_HEIGHT / 2))
        y = Game::screen->height - SCREEN_HEIGHT;
    else
        y = Game::ship->getY() - (SCREEN_HEIGHT / 2);

    view->setCenter(x + (SCREEN_WIDTH / 2), y + (SCREEN_HEIGHT / 2));
}

void Camera::draw(sf::RenderWindow& w)
{
    w.setView(*view);
}

Camera::~Camera()
{
    //dtor
}
