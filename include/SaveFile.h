#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <sys/stat.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "OverworldData.h"

#define FILE_SIZE 81        //each file is 81 bytes

#define WIDTH 600
#define HEIGHT 80

class SaveFile
{
public:
    SaveFile(int x, int y, int index);
    virtual ~SaveFile();

    //save file data
    time_t startTimer;
    time_t currentTimer;
    struct tm startTime;
    struct tm currentTime;
    float timeSpentPlaying;     //in seconds
    sf::Clock clock;

    int getX();
    int getY();
    int getIndex();

    void tick();    void draw(sf::RenderWindow& w);

private:
    int x, y, index;
    bool newFile;
    bool corrupted;

    int level;

    sf::RectangleShape rect;
    sf::Text text;
};

#endif // SAVEFILE_H
