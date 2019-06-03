#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
    //design these better in the future, but for right now just a list of textures
public:
    ResourceManager();
    virtual ~ResourceManager();

    //graphics
    sf::Texture blockTexture;
    sf::Texture overworldShipTexture;
    sf::Texture levelShipTexture;
    sf::Texture holeTexture;
    sf::Texture coveredHoleTexture;
    sf::Texture savePointTexture;
    sf::Texture titleTexture;
    sf::Texture saveFileTexture;
    sf::Image icon;

    //sound/music
    sf::Music titleSong;
    sf::Music mainSong;
    sf::Music finalMazeSong;
    sf::Music messageBreakSong;
    sf::Music creditsSong;
};

#endif // RESOURCEMANAGER_H
