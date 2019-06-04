#include "SaveFile.h"

SaveFile::SaveFile(int x, int y, int index)
{
    this->x = x;
    this->y = y;
    this->index = index;

    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(WIDTH, HEIGHT));
    rect.setTexture(&Game::resourceManager.saveFileTexture);

    //set up HUD
        //if file corresponding to index exists, display data
        //otherwise display NEW FILE

    //move this to its own function in case file data changes and this needs to be re-set
    text.setFont(Game::resourceManager.font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 4, y + 4);
    struct stat buffer;
    if (stat(Game::saveFileNames[index], &buffer) == 0) {
        std::string fileText = "Start: ";
        newFile = false;
        Game::gameFile.open(Game::saveFileNames[index], std::fstream::in | std::fstream::binary);
        //(make sure checksum "checks :^)" out)
        //get start time
        Game::gameFile.read((char* ) &startTime, sizeof(struct tm));
        //get time last saved
        Game::gameFile.read((char* ) &currentTime, sizeof(struct tm));
        //get level
        Game::gameFile.read((char* ) &level, sizeof(char));
        Game::gameFile.close();

        //ABSOLUTE BEAUTY. If I can find a better way to do this, I will
        fileText += std::to_string(startTime.tm_mon + 1);
        fileText += "/";
        fileText += std::to_string(startTime.tm_mday);
        fileText += "/";
        fileText += std::to_string(startTime.tm_year + 1900);
        fileText += "  ";
        fileText += std::to_string(startTime.tm_hour);
        fileText += ":";
        fileText += std::to_string(startTime.tm_min);
        fileText += ":";
        fileText += std::to_string(startTime.tm_sec);
        fileText += "\nLast Saved: ";
        fileText += std::to_string(currentTime.tm_mon + 1);
        fileText += "/";
        fileText += std::to_string(currentTime.tm_mday);
        fileText += "/";
        fileText += std::to_string(currentTime.tm_year + 1900);
        fileText += "  ";
        fileText += std::to_string(currentTime.tm_hour);
        fileText += ":";
        fileText += std::to_string(currentTime.tm_min);
        fileText += ":";
        fileText += std::to_string(currentTime.tm_sec);
        fileText += "\nLevel ";
        fileText += std::to_string(level);
        text.setString(fileText);
    } else {
        text.setString("New File");
        newFile = true;
    }
}

int SaveFile::getX()
{
    return x;
}

int SaveFile::getY()
{
    return y;
}

int SaveFile::getIndex()
{
    return index;
}

void SaveFile::tick()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (sf::Mouse::getPosition(Game::window).x >= x && sf::Mouse::getPosition(Game::window).x < x + WIDTH && sf::Mouse::getPosition(Game::window).y >= y && sf::Mouse::getPosition(Game::window).y < y + HEIGHT) {
            //if the file for this save exists
                //if the checksum at the end of the file doesn't match up, throw a "file seems to be corrupted" error.
                //otherwise load the data and go to the overworld state
            //else
                //start a new game and go to the overworld state
            std::cout << "clicked " << index << std::endl;
            if (newFile == true) {
                Game::setLevelNum(0);
                Game::setOldLevelNum(0);
                //get the start date of the
                time(&startTimer);
                std::memcpy(&startTime, localtime(&startTimer), sizeof(struct tm));
                Game::startTime = startTime;
            } else {
                Game::startTime.tm_year = startTime.tm_year;
                Game::startTime.tm_mon = startTime.tm_mon;
                Game::startTime.tm_mday = startTime.tm_mday;
                Game::startTime.tm_hour = startTime.tm_hour;
                Game::startTime.tm_min = startTime.tm_min;
                Game::startTime.tm_sec = startTime.tm_sec;
                Game::currentTime.tm_year = currentTime.tm_year;
                Game::currentTime.tm_mon = currentTime.tm_mon;
                Game::currentTime.tm_mday = currentTime.tm_mday;
                Game::currentTime.tm_hour = currentTime.tm_hour;
                Game::currentTime.tm_min = currentTime.tm_min;
                Game::currentTime.tm_sec = currentTime.tm_sec;
                Game::setLevelNum(level);
                Game::setOldLevelNum(level);
                Game::overworldShip.setPosition(holeNextShipXs[level - 1], holeNextShipYs[level - 1]);
                Game::overworldShip.setReturnPosition(holeNextShipXs[level - 1], holeNextShipYs[level - 1]);
                Game::overworld.setReturnIndex(level);
            }
            Game::setSaveFileIndex(index);
            Game::level.load();
            Game::overworld.load();
            Game::setState(Game::STATE_OVERWORLD);
        }
    }

    //no need to set rect here since this won't be moving
    rect.setPosition(x, y);
}

void SaveFile::draw(sf::RenderWindow& w)
{
    w.draw(rect);
    w.draw(text);
}

SaveFile::~SaveFile()
{
    //dtor
}
