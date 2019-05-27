#include <SFML/Graphics.hpp>
#include "Game.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 608

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racer");

    //sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

    //main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Game::ship->tick();

        //load new level if the level has changed
        if (Game::getLevel() != Game::getOldLevel()) {
            window.clear();
            Game::updateOldLevel();
            Game::screen->loadNewScreen(Game::getLevel());
        }

        if (Game::ship->getState() == Game::ship->STATE_DEAD)
            window.close();

        window.clear(sf::Color::White);
        Game::screen->drawScreen(window);
        Game::ship->draw(window);
        window.display();
    }

    return 0;
}
