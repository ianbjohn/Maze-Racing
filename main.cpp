#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racing");

    //initialize game settings
    Game game;

    //main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Game::ship->tick();
        Game::portal->tick();
        Game::camera->followShip();

        //load new level if the level has changed
        if (Game::getLevel() != Game::getOldLevel()) {
            window.clear();
            Game::updateOldLevel();
            Game::screen->loadNewScreen(Game::getLevel());
        }

        if (Game::ship->getState() == Game::ship->STATE_DEAD)
            window.close();

        window.clear(sf::Color::White);
        Game::camera->draw(window);
        Game::screen->drawScreen(window);
        Game::portal->draw(window);
        Game::ship->draw(window);
        window.display();
    }

    return 0;
}
