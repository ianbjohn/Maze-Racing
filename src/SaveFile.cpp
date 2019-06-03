#include "SaveFile.h"

SaveFile::SaveFile(int x, int y, int index)
{
    this->x = x;
    this->y = y;
    this->index = index;

    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(WIDTH, HEIGHT));
    rect.setTexture(&Game::resourceManager.saveFileTexture);
    //rect.setTextureRect(sf::RectangleShape());
    //set up HUD
        //if file corresponding to index exists, display data
        //otherwise
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
            //levelNum = 0;
            //levelNumOld = 0;
            //level.load();
            //overworld.load();
        }
    }

    //no need to set rect here since this won't be moving
    rect.setPosition(x, y);
}

void SaveFile::draw(sf::RenderWindow& w)
{
    w.draw(rect);
}

SaveFile::~SaveFile()
{
    //dtor
}
