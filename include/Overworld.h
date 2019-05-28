#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "Screen.h"


class Overworld : public Screen
{
public:
    Overworld();
    virtual ~Overworld();

    //have a vector list of hole entities
    void load();

private:
};

#endif // OVERWORLD_H
