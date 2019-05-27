#ifndef SHIP_H
#define SHIP_H
#include "Screen.h"
#define SPEED 0.5

class Ship
{
public:
    Ship(float x, float y);
    virtual ~Ship();

    int getState();
    float getX();
    float getY();
    void setState(int state);
    void setPosition(sf::Vector2f v);

    int checkBackgroundCollision();
    int checkPortalCollision();
    void tick();
    void draw(sf::RenderWindow& w);

    enum directions {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};
    enum states {STATE_STILL, STATE_MOVING, STATE_DEAD};

private:
    float x, y;
    int width, height, dir;
    int state;
    sf::RectangleShape rect;
    sf::Texture texture;
};

#endif // SHIP_H
