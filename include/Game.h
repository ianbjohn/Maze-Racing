#ifndef GAME_H
#define GAME_H
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

class Level;

class Game
{
public:
    Game();
    virtual ~Game();

    static int getState();
    static int getOldState();
    static int getLevelNum();
    static int getOldLevelNum();

    static void setState(int state);
    static void setLevelNum(int l);
    static void updateOldState();
    static void updateOldLevelNum();

    enum States {STATE_TITLE, STATE_PLAY, STATE_GAMEOVER};

    static Overworld* overworld;
    static Level* level;
    static Camera* camera;

    static LevelShip* levelShip;
    static OverworldShip* overworldShip;

private:
    static int state;
    static int stateOld;
    static int levelNum;
    static int levelNumOld;
};

#endif // GAME_H
