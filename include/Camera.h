#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>


class Camera
{
public:
    Camera();
    virtual ~Camera();

    float getX();
    float getY();

    void followShip();
    void draw(sf::RenderWindow& w);

private:
    float x, y;
    sf::View* view;
};

#endif // CAMERA_H
