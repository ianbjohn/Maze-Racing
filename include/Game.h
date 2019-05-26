#ifndef GAME_H
#define GAME_H

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

private:
    static int state;
    static int stateOld;
    static int level;
    static int levelOld;
};

#endif // GAME_H
