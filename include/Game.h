#ifndef GAME_H
#define GAME_H
#include "Screen.h"
#include "Camera.h"
#include "Ship.h"
#include "Portal.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 608
#define SCREEN_WIDTH_TILES 25
#define SCREEN_HEIGHT_TILES 19


class Game
{
public:
    Game();
    virtual ~Game();

    static int getState();
    static int getOldState();
    static int getLevel();
    static int getOldLevel();

    static void setState(int state);
    static void setLevel(int level);
    static void updateOldState();
    static void updateOldLevel();

    enum States {STATE_TITLE, STATE_PLAY, STATE_GAMEOVER};

    static Screen* screen;
    static Camera* camera;

    //keep track of entities
    static Ship* ship;
    static Portal* portal;

private:
    static int state;
    static int stateOld;
    static int level;
    static int levelOld;
};

#endif // GAME_H
