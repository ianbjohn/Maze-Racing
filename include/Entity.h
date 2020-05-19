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

    int getID();
    int getState();
    float getX();
    float getY();
    int getWidth();
    int getHeight();
    const unsigned int* getCollisionData();
    void setState(int state);
    void setPosition(float x, float y);
    void setDir(int d);

    bool checkBackgroundCollision(Screen& s);
    bool checkEntityCollision(Entity& e);
    bool checkPreciseCollision(float x, float y, float xh, float yh, const unsigned int* cdata);

    enum directions {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};

    virtual void tick() = 0;
    void draw(sf::RenderWindow& w);

protected:
    int ent_id;
    float x, y;
    int width, height, dir;
    int state;
    sf::RectangleShape rect;
};

#endif // ENTITY_H
