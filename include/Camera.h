#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Entity.h"


class Camera
{
public:
    Camera();
    virtual ~Camera();

    float getX();
    float getY();

    void setPosition(float x, float y);

    void follow(Entity& e, Screen& s);
    void draw(sf::RenderWindow& w);

private:
    float x, y;
    sf::View view;
};

#endif // CAMERA_H
