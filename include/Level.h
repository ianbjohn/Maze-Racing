#ifndef LEVEL_H
#define LEVEL_H
#include "Screen.h"


class Level : public Screen
{
public:
    Level();
    virtual ~Level();

    void loadNewLevel(int levelIndex);


private:
};

#endif // LEVEL_H
