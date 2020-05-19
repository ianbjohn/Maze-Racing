#include "Game.h"
#include "OverworldData.h"
#include "SavePoint.h"

SavePoint::SavePoint()
{
    ent_id = 4;
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
            unsigned char fileBuffer[FILE_SIZE];

            Game::gameFile.open(Game::saveFileNames[index], std::fstream::out | std::fstream::binary);
            //update the current saved time
            time(&Game::saveFiles[index].currentTimer);
            std::memcpy(&Game::saveFiles[index].currentTime, localtime(&Game::saveFiles[index].currentTimer), sizeof(struct tm));
            //update time spent playing
            Game::saveFiles[index].timeSpentPlaying += Game::saveFiles[index].clock.getElapsedTime().asSeconds();

            //save the data
            std::memcpy(&fileBuffer[0], &(Game::saveFiles[index].startTime), sizeof(struct tm));
            std::memcpy(&fileBuffer[sizeof(struct tm)], &(Game::saveFiles[index].currentTime), sizeof(struct tm));
            std::memcpy(&fileBuffer[2 * sizeof(struct tm)], &(Game::saveFiles[index].timeSpentPlaying), sizeof(float));
            char writeLevel = (char) Game::getLevelNum();
            std::memcpy(&fileBuffer[(2 * sizeof(struct tm)) + sizeof(float)], &writeLevel, sizeof(char));

            //Add a checksum at the end
            int checksum = 0;
            for (unsigned int i = 0; i < FILE_SIZE - sizeof(int); i++)
                checksum += fileBuffer[i];
            std::memcpy(&fileBuffer[(2 * sizeof(struct tm)) + sizeof(float) + sizeof(char)], &checksum, sizeof(int));

            Game::gameFile.write((char* ) fileBuffer, FILE_SIZE);
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
