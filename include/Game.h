#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include "ResourceManager.h"
#include "SaveFile.h"
#include "Camera.h"
#include "Screen.h"
#include "Entity.h"
#include "Level.h"
#include "LevelShip.h"
#include "Overworld.h"
#include "OverworldShip.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH_TILES 20
#define SCREEN_HEIGHT_TILES 15
#define NUM_SAVEFILES 3

class Level;
class SaveFile;

class Game
{
public:
    Game();
    virtual ~Game();

    static bool checkIfNewGame();
    static int getState();
    static int getOldState();
    static int getLevelNum();
    static int getOldLevelNum();
    static int getSaveFileIndex();

    static void setState(int state);
    static void setLevelNum(int l);
    static void setOldLevelNum(int l);
    static void updateOldState();
    static void updateOldLevelNum();
    static void setSaveFileIndex(int i);

    enum States {STATE_TITLE, STATE_FILESELECT, STATE_OVERWORLD, STATE_LEVEL, STATE_MSGBREAK, STATE_CREDITS};

    static ResourceManager resourceManager;
    static std::fstream gameFile;
    static const char* saveFileNames[3];
    static SaveFile saveFiles[3];

    static sf::RectangleShape titleRect;

    static Overworld overworld;
    static Level level;
    static Camera camera;

    static LevelShip levelShip;
    static OverworldShip overworldShip;

    static sf::RenderWindow window;
    static sf::Event event;
    static void run();

private:
    static bool newGame;    //1 - game has been loaded from a file
    static int state;
    static int stateOld;
    static int levelNum;
    static int levelNumOld;
    static int saveFileIndex;

    static const sf::Color backgroundColors[6];
};

#endif // GAME_H
