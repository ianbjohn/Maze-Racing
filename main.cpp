#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racing");
    window.setFramerateLimit(60);

    //initialize game settings
    Game game;
    //sf::Clock gameClock;

    //main loop
    while (window.isOpen()) {
        //float startTime = gameClock.getElapsedTime().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Game::levelShip->tick();
        Game::camera->follow(Game::levelShip, Game::level);

        //load new level if the level has changed
        if (Game::getLevelNum() != Game::getOldLevelNum()) {
            window.clear();
            Game::updateOldLevelNum();
            Game::level->cleanUpScreen();
            Game::level->loadNewLevel(Game::getLevelNum());
        }

        if (Game::levelShip->getState() == Game::levelShip->STATE_DEAD)
            window.close();

        window.clear(sf::Color::White);
        Game::camera->draw(window);
        Game::level->drawScreen(window);
        Game::levelShip->draw(window);
        window.display();

        //float elapsedTime = gameClock.getElapsedTime().asSeconds();
        //int fps = (int) (1.0f / elapsedTime);
        //std::cout << fps << std::endl;
    }

    return 0;
}
