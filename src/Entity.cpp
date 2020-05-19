#include "Game.h"
#include "Entity.h"
#include "CollisionData.h"

Entity::Entity()
{
    
}

int Entity::getID()
{
    return ent_id;
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

const unsigned int* Entity::getCollisionData()
{
    //Get the right array of collision data based on ID and direction
    return entityHitboxes[ent_id][dir];
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

bool Entity::checkBackgroundCollision(Screen& s)
{
    //rudimentary 4-corner collision checking, followed by a more precise one if a general collision was detected
    //As said elsewhere, there's no information hiding with collision data yet. So this is something to likely do in the future.
    int tile = s.getScreenTile(x / width, y / height);
    if (tile == 1) return Entity::checkPreciseCollision((x / width) * width, (y / height) * height, ((x / width) * width) + width, ((y / height) * height) + height, blockHitbox);
    tile = s.getScreenTile((x + width - 1) / width, y / height);
    if (tile == 1) return Entity::checkPreciseCollision((x / width) * width, (y / height) * height, (((x + width - 1) / width) * width) + width, ((y / height) * height) + height, blockHitbox);
    tile = s.getScreenTile(x / width, (y + height - 1) / height);
    if (tile == 1) return Entity::checkPreciseCollision((x / width) * width, (y / height) * height, ((x / width) * width) + width, (((y + height - 1) / height) * height) + height, blockHitbox);
    tile = s.getScreenTile((x + width - 1) / width, (y + height - 1) / height);
    if (tile == 1) return Entity::checkPreciseCollision((x / width) * width, (y / height) * height, (((x + width - 1) / width) * width) + width, (((y + height - 1) / height) * height) + height, blockHitbox);

    return false;
}

bool Entity::checkEntityCollision(Entity& e)
{
    //I imagine a general entity collision function with an entity pointer wouldn't be much harder
    //somewhat similar to background collision, check each side of the hitbox to see if its outside the portal's hitbox, and if all of them fail, there was a collision
    //again, if entities in later games have different hitbox shapes, use a different approach
    if (x >= (e.getX() + e.getWidth() - 1)) return false;
    if ((x + width - 1) < (e.getX())) return false;
    if (y >= (e.getY() + e.getHeight() - 1)) return false;
    if ((y + height - 1) < (e.getY())) return false;

    //At this point, there's a collision of some time
    //Check for a collision more precisely
    return Entity::checkPreciseCollision(e.getX(), e.getY(), e.getX() + e.getWidth(), e.getY() + e.getHeight(), e.getCollisionData());
}

//A general box-box collision is assumed to have occured upon calling this function
//WILL NOT YET WORK, some things outside of function yet to be implemented (entity IDs, fully structured collision data), and so function has not been tested/debugged yet
bool Entity::checkPreciseCollision(float x, float y, float xh, float yh, const unsigned int* cdata) {
    //Data for the collision box
    int cx, cy, cxh, cyh;
    bool h_side, v_side;    //Whether object 2 is to the left/top (0) or right/bottom (1) of object 1

    //Find vertical start and size of collision box
    if (y < this->y) {
        v_side = false;
        cy = 0;
        cyh = yh - this->y;
    }
    else {
        v_side = true;
        cy = y - this->y;
        cyh = height;
    }

    //Find horizontal start and size of collision box
    if (x < this->x) {
        h_side = false;
        cx = 0;
        cxh = xh - this->x;
    }
    else {
        h_side = true;
        cx = x - this->x;
        cxh = width;
    }

    for (int i = cy; i < cyh; i++) {
        unsigned int collision_row_2;

        //Use some indexing math to figure out which row of object 2's collision data to load based on where it is relative to object 1
        if (v_side)
            collision_row_2 = cdata[i - (int)(y - this->y)];
        else
            collision_row_2 = cdata[i + (int)(y - this->y)];

        //Since both hitboxes are the same size, simply shifting will fill every other bit (aka pixel that wasn't in the collision) with 0
        if (h_side)
            collision_row_2 >>= cx;
        else
            collision_row_2 <<= (width - cxh);

        //If the two bitfields of the collision data rows intersected together is non-zero, there's a collision on this row, and we are done
        if (getCollisionData()[i] & collision_row_2 != 0)
            return true;
    }

    //No collision detected on any relevant row
    return false;
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
