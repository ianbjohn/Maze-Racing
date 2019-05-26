#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Ship.h"
#include "Game.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 608

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racer");

    Screen screen;
    screen.loadNewScreen(0);

    Ship ship(64, 64);

    //sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

    //main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ship.tick(&screen);

        //load new level if the level has changed
        if (Game::getLevel() != Game::getOldLevel()) {
            window.clear();
            Game::updateOldLevel();
            screen.loadNewScreen(Game::getLevel());
            ship.setPosition(sf::Vector2f(64, 64));
            ship.setState(Ship::STATE_STILL);
        }

        if (ship.getState() == ship.STATE_DEAD)
            window.close();

        window.clear(sf::Color::White);
        screen.drawScreen(window);
        ship.draw(window);
        window.display();
    }

    return 0;
}
