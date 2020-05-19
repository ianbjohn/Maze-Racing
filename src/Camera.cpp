#include "Game.h"
#include "Screen.h"
#include "Camera.h"

Camera::Camera()
{
    x = 0;
    y = 0;
    view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
}

float Camera::getX()
{
    return x;
}

float Camera::getY()
{
    return y;
}

void Camera::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    view.setCenter(x + (SCREEN_WIDTH / 2), y + (SCREEN_HEIGHT / 2));
}

void Camera::follow(Entity& e, Screen& s)
{
    //put the ship in the center of the camera view, unless he's at one of the corners of the room
    if (e.getX() < SCREEN_WIDTH / 2)
        x = 0;
    else if (e.getX() >= s.width - 1 - (SCREEN_WIDTH / 2))
        x = s.width - SCREEN_WIDTH;
    else
        x = e.getX() - (SCREEN_WIDTH / 2);

    if (e.getY() < SCREEN_HEIGHT / 2)
        y = 0;
    else if (e.getY() >= s.height - 1 - (SCREEN_HEIGHT / 2))
        y = s.height - SCREEN_HEIGHT;
    else
        y = e.getY() - (SCREEN_HEIGHT / 2);

    view.setCenter(x + (SCREEN_WIDTH / 2), y + (SCREEN_HEIGHT / 2));
}

void Camera::draw(sf::RenderWindow& w)
{
    w.setView(view);
}

Camera::~Camera()
{
    //dtor
}
