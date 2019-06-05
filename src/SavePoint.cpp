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
            int index = Game::getSaveFileIndex();

            Game::gameFile.open(Game::saveFileNames[index], std::fstream::out | std::fstream::binary);
            //update the current saved time
            time(&Game::saveFiles[index].currentTimer);
            std::memcpy(&Game::saveFiles[index].currentTime, localtime(&Game::saveFiles[index].currentTimer), sizeof(struct tm));
            //update time spent playing
            Game::saveFiles[index].timeSpentPlaying += Game::saveFiles[index].clock.getElapsedTime().asSeconds();

            //date/time of when we started playing
            Game::gameFile.write((char* ) &Game::saveFiles[index].startTime, sizeof(struct tm));
            //date/time of when we're saving
            Game::gameFile.write((char* ) &Game::saveFiles[index].currentTime, sizeof(struct tm));
            //time spent playing
            Game::gameFile.write((char* ) &(Game::saveFiles[index].timeSpentPlaying), sizeof(float));
            //level
            char writeLevel = (char) Game::getLevelNum();
            Game::gameFile.write(&writeLevel, sizeof(char));     //maybe change level to a byte later, but not a huge deal
            //Add a checksum at the end
            Game::gameFile.close();
            Game::saveFiles[index].clock.restart();
            std::cout << "File saved." << std::endl;      //make a GUI notification
        }
    }

    rect.setPosition(x, y);
}

SavePoint::~SavePoint()
{
    //dtor
}
