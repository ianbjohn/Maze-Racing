#ifndef PORTAL_H
#define PORTAL_H
#include <SFML/Graphics.hpp>


class Portal
{
public:
    Portal(float x, float y);
    virtual ~Portal();

    void setPosition(sf::Vector2f v);

private:
    float x, y;
    int width, height;
    sf::RectangleShape rect;
    sf::Texture texture;
};

#endif // PORTAL_H
