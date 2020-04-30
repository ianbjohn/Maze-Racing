#include "SaveFile.h"

SaveFile::SaveFile(int x, int y, int index)
{
    this->x = x;
    this->y = y;
    this->index = index;

    corrupted = false;

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
    struct stat stats;
    if (stat(Game::saveFileNames[index], &stats) == 0) {
        Game::gameFile.open(Game::saveFileNames[index], std::fstream::in | std::fstream::binary);

        //make sure the file size is correct
        Game::gameFile.seekg(0, Game::gameFile.end);
        int size = Game::gameFile.tellg();
        if (size != FILE_SIZE) {
            text.setString("CORRUPTED");
            corrupted = true;
            return;
        }

        //load file into buffer to make sure checksum matches and file isn't corrupted
        Game::gameFile.seekg(0, Game::gameFile.beg);
        unsigned char fileBuffer[FILE_SIZE];
        Game::gameFile.read((char* ) fileBuffer, FILE_SIZE);

        int checksum = *((int* ) &fileBuffer[FILE_SIZE - sizeof(int)]);
        //std::cout << "Checksum: " << checksum << std::endl;
        int checksumTest = 0;
        for (unsigned int i = 0; i < FILE_SIZE - sizeof(int); i++)
            checksumTest += (unsigned char) fileBuffer[i];
        //std::cout << "ChecksumTest: " << checksumTest << std::endl;
        if (checksumTest != checksum) {
            text.setString("CORRUPTED");
            corrupted = true;
            return;
        }

        std::string fileText = "Start: ";
        newFile = false;
        //get data from save file
        std::memcpy(&startTime,         &fileBuffer[0],                                         sizeof(struct tm));
        std::memcpy(&currentTime,       &fileBuffer[sizeof(struct tm)],                         sizeof(struct tm));
        std::memcpy(&timeSpentPlaying,  &fileBuffer[2 * sizeof(struct tm)],                     sizeof(float));
        std::memcpy(&level,             &fileBuffer[(2 * sizeof(struct tm)) + sizeof(float)],   sizeof(char));
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
        fileText += "    Time Spent Playing: ";
        fileText += std::to_string(((int) timeSpentPlaying) / 60 / 60);   //hours
        fileText += ":";
        fileText += std::to_string(((int) timeSpentPlaying / 60) % 60); //minutes
        fileText += ":";
        fileText += std::to_string(((int) timeSpentPlaying) % 60);      //seconds
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
        //sf::Vector2f scale = sf::Vector2f(WIDTH, HEIGHT) / Game::window.getSize();
        sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);

        if (sf::Mouse::getPosition(Game::window).x * scale.x >= x && sf::Mouse::getPosition(Game::window).x * scale.x < x + WIDTH && sf::Mouse::getPosition(Game::window).y * scale.y >= y && sf::Mouse::getPosition(Game::window).y * scale.y < y + HEIGHT) {
            if (corrupted == true)
                return;

            clock.restart();
            if (newFile == true) {
                timeSpentPlaying = 0.0f;
                Game::setLevelNum(0);
                Game::setOldLevelNum(0);
                //get the start date of the file
                time(&startTimer);
                std::memcpy(&startTime, localtime(&startTimer), sizeof(struct tm));
            } else {
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
