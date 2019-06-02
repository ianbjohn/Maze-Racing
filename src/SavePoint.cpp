#include "Game.h"
#include "OverworldData.h"
#include "SavePoint.h"

SavePoint::SavePoint()
{
    width = 32;
    height = 32;

    rect.setPosition(sf::Vector2f(this->x, this->y));
    rect.setSize(sf::Vector2f(width, height));
    rect.setTexture(&Game::resourceManager.savePointTexture);
}

void SavePoint::tick()
{
    if (checkEntityCollision(Game::overworldShip) == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            //the number at the end of the savefile name should correspond to the savefile index
            Game::gameFile.open("savefile0.sav", std::fstream::out | std::fstream::binary);
            int writeInt = Game::getLevelNum();
            Game::gameFile.write((char* ) &writeInt, sizeof(int));
            //Add time spent playing
            //Add data / time we started playing, etc
            //Add a checksum at the end
            Game::gameFile.close();
            std::cout << "File saved." << std::endl;
        }
    }

    rect.setPosition(x, y);
}

SavePoint::~SavePoint()
{
    //dtor
}
