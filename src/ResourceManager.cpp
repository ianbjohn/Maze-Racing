#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    blockTexture.loadFromFile("gfx/block.png");
    overworldShipTexture.loadFromFile("gfx/overworldship.png");
    levelShipTexture.loadFromFile("gfx/levelship.png");
    holeTexture.loadFromFile("gfx/hole.png");
    coveredHoleTexture.loadFromFile("gfx/coveredhole.png");
}

ResourceManager::~ResourceManager()
{
    //dtor
}
