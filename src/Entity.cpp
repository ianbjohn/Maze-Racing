#include "Game.h"
#include "Entity.h"

Entity::Entity()
{
    //ctor
}

int Entity::getState()
{
    return state;
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

int Entity::getWidth()
{
    return width;
}

int Entity::getHeight()
{
    return height;
}

void Entity::setState(int state)
{
    this->state = state;
}

void Entity::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Entity::setDir(int d)
{
    dir = d;
}

int Entity::checkBackgroundCollision(Screen& s)
{
    //rudimentary 4-corner collision checking
    //once more diverse entity types are created in future projects, approach differently
    int tile = s.getScreenTile(x / 32, y / 32);
    if (tile == 1) return 1;
    tile = s.getScreenTile((x + width - 1) / 32, y / 32);
    if (tile == 1) return 1;
    tile = s.getScreenTile(x / 32, (y + height - 1) / 32);
    if (tile == 1) return 1;
    tile = s.getScreenTile((x + width - 1) / 32, (y + height - 1) / 32);
    if (tile == 1) return 1;

    return 0;
}

int Entity::checkEntityCollision(Entity& e)
{
    //I imagine a general entity collision function with an entity pointer wouldn't be much harder
    //somewhat similar to background collision, check each side of the hitbox to see if its outside the portal's hitbox, and if all of them fail, there was a collision
    //again, if entities in later games have different hitbox shapes, use a different approach
    if (x >= (e.getX() + e.getWidth() - 1)) return 0;
    if ((x + width - 1) < (e.getX())) return 0;
    if (y >= (e.getY() + e.getHeight() - 1)) return 0;
    if ((y + height - 1) < (e.getY())) return 0;

    return 1;
}

void Entity::draw(sf::RenderWindow& w)
{
    if (x >= Game::camera.getX() && x < Game::camera.getX() + SCREEN_WIDTH && y >= Game::camera.getY() && y < Game::camera.getY() + SCREEN_HEIGHT);
        w.draw(rect);
}

Entity::~Entity()
{
    //dtor
}
