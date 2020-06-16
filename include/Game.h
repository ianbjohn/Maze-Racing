#ifndef GAME_H
#define GAME_H
#include <TGUI/TGUI.hpp>
#include <SFML/System.hpp>
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
#include "MessageBox.h"
#include "Overworld.h"
#include "OverworldShip.h"
#include "Tutorial.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH_TILES 20
#define SCREEN_HEIGHT_TILES 15
#define NUM_SAVEFILES 3
#define NUM_GAMESTATES 7

class Level;
class SaveFile;
class Tutorial;

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

    static void loadTutorial();

    enum States {STATE_TITLE, STATE_FILESELECT, STATE_OVERWORLD, STATE_TUTORIAL, STATE_LEVEL, STATE_MSGBREAK, STATE_CREDITS};

    static ResourceManager resourceManager;
    static std::fstream gameFile;
    static const char* saveFileNames[NUM_SAVEFILES];
    static SaveFile saveFiles[NUM_SAVEFILES];

    static sf::RectangleShape titleRect;

    static Overworld overworld;
    static Level level;
    static Camera camera;
    static Tutorial tutorial;

    static LevelShip levelShip;
    static OverworldShip overworldShip;

    static sf::RenderWindow window;
    static sf::Event event;
    static tgui::Gui gui;
    static void run();

private:
    //No real need to make these private just to have only getters/setters for them, we can probably make them public
    static bool newGame;    //1 - game has been loaded from a file
    static int state;
    static int stateOld;
    static int levelNum;
    static int levelNumOld;
    static int saveFileIndex;

    static const sf::Color backgroundColors[NUM_GAMESTATES];
};

#endif // GAME_H
