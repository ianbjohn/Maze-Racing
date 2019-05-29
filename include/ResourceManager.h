#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <SFML/Graphics.hpp>

class ResourceManager
{
    //design these better in the future, but for right now just a list of textures
public:
    ResourceManager();
    virtual ~ResourceManager();

    sf::Texture blockTexture;
    sf::Texture overworldShipTexture;
    sf::Texture levelShipTexture;
    sf::Texture holeTexture;
    sf::Texture coveredHoleTexture;
};

#endif // RESOURCEMANAGER_H
