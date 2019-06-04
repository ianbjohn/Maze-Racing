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
        //std::string fileText = "";
        newFile = false;
        Game::gameFile.open(Game::saveFileNames[index], std::fstream::in | std::fstream::binary);
        int readInt;
        //(make sure checksum "checks :^)" out
        Game::gameFile.read((char* ) &readInt, sizeof(char));
        level = readInt;
        text.setString(std::to_string(level));
        Game::gameFile.close();
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
            } else {
                Game::setLevelNum(level);
                Game::setOldLevelNum(level);
                Game::overworldShip.setPosition(holeNextShipXs[level - 1], holeNextShipYs[level - 1]);
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
