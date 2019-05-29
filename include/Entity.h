#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"


class Entity
{
public:
    Entity();
    virtual ~Entity();

    int getState();
    float getX();
    float getY();
    int getWidth();
    int getHeight();
    void setState(int state);
    void setPosition(float x, float y);
    void setDir(int d);

    int checkBackgroundCollision(Screen& s);
    int checkEntityCollision(Entity& e);

    enum directions {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};

    virtual void tick() = 0;
    void draw(sf::RenderWindow& w);

protected:
    float x, y;
    int width, height, dir;
    int state;
    sf::RectangleShape rect;
};

#endif // ENTITY_H
