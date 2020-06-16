#include "Game.h"

int main()
{
    //initialize game settings
    Game();
    //sf::Clock gameClock;

    //float startTime = gameClock.getElapsedTime().asSeconds();

    Game::run();

    //float elapsedTime = gameClock.getElapsedTime().asSeconds();
    //int fps = (int) (1.0f / elapsedTime);
    //std::cout << fps << std::endl;

    return 0;
}
