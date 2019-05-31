#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    blockTexture.loadFromFile("gfx/block.png");
    overworldShipTexture.loadFromFile("gfx/overworldship.png");
    levelShipTexture.loadFromFile("gfx/levelship.png");
    holeTexture.loadFromFile("gfx/hole.png");
    coveredHoleTexture.loadFromFile("gfx/coveredhole.png");
    savePointTexture.loadFromFile("gfx/savepoint.png");

    titleSong.openFromFile("music/title.ogg");
    titleSong.setLoop(true);
    mainSong.openFromFile("music/main_song.ogg");
    mainSong.setLoop(true);
    finalMazeSong.openFromFile("music/final_maze_song.ogg");
    finalMazeSong.setLoop(true);
    messageBreakSong.openFromFile("music/message_break.ogg");
    creditsSong.openFromFile("music/credits.ogg");
}

ResourceManager::~ResourceManager()
{
    //dtor
}
