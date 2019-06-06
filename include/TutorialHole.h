#ifndef TUTORIALHOLE_H
#define TUTORIALHOLE_H

#include "Hole.h"


class TutorialHole : public Hole
{
public:
    TutorialHole();
    virtual ~TutorialHole();

    void tick();

private:
};

#endif // TUTORIALHOLE_H
