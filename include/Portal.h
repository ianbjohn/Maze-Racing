#ifndef PORTAL_H
#define PORTAL_H
#include <SFML/Graphics.hpp>


//maybe make a more general Entity parent class, if more entities are added
class Portal
{
public:
    Portal(float x, float y);
    virtual ~Portal();

    float getX();   //at least until I can figure out how to properly return a Vector2f
    float getY();
    int getWidth();
    int getHeight();
    void setPosition(sf::Vector2f v);
    void tick();
    void draw(sf::RenderWindow& w);

private:
    float x, y;
    int width, height;
    sf::RectangleShape rect;
    sf::Texture texture;
};

#endif // PORTAL_H
