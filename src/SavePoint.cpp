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
            Game::gameFile.open(Game::saveFileNames[Game::getSaveFileIndex()], std::fstream::out | std::fstream::binary);
            //update the current saved time
            time(&Game::currentTimer);
            std::memcpy(&Game::currentTime, localtime(&Game::currentTimer), sizeof(struct tm));

            //date/time of when we started playing
            Game::gameFile.write((char* ) &Game::startTime, sizeof(struct tm));
            //date/time of when we're saving
            Game::gameFile.write((char* ) &Game::currentTime, sizeof(struct tm));
            //level
            char writeLevel = (char) Game::getLevelNum();
            Game::gameFile.write(&writeLevel, sizeof(char));     //maybe change level to a byte later, but not a huge deal
            //Add a checksum at the end
            Game::gameFile.close();
            std::cout << "File saved." << std::endl;      //make a GUI notification
        }
    }

    rect.setPosition(x, y);
}

SavePoint::~SavePoint()
{
    //dtor
}
