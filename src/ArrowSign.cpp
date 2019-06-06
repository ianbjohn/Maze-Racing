#include "Game.h"
#include "ArrowSign.h"

ArrowSign::ArrowSign()
{
    width = 32;
    height = 32;

    x = 480;
    y = 1856;
    rect.setSize(sf::Vector2f(width, height));
    rect.setTexture(&Game::resourceManager.arrowSignTexture);
    rect.setPosition(x, y);
}

void ArrowSign::tick()
{
    //empty function, probably bad practice :(
}

ArrowSign::~ArrowSign()
{
    //dtor
}
