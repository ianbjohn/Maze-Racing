#include <iostream>
#include "Tutorial.h"

Tutorial::Tutorial()
{
    //set up everything here
    tutHole.setSize(sf::Vector2f(32, 32));
    tutHole.setPosition(50, 67);
    tutHole.setTexture(&Game::resourceManager.holeTexture);
    tutTextHole.setFont(Game::resourceManager.font);
    tutTextHole.setCharacterSize(30);
    tutTextHole.setFillColor(sf::Color::Black);
    tutTextHole.setPosition(98, 67);
    tutTextHole.setString("< This is a hole. These take you to the\nlevels in the maze. They become covered\nafter a level is completed.");

    tutWall.setSize(sf::Vector2f(32, 32));
    tutWall.setPosition(50, 213);
    tutWall.setTexture(&Game::resourceManager.blockTexture);
    tutTextWall.setFont(Game::resourceManager.font);
    tutTextWall.setCharacterSize(30);
    tutTextWall.setFillColor(sf::Color::Black);
    tutTextWall.setPosition(98, 213);
    tutTextWall.setString("< This is a wall block. Avoid these at all\ncosts, or you will have to start over from the\nbeginning, or where you last saved.");

    tutSave.setSize(sf::Vector2f(32, 32));
    tutSave.setPosition(50, 360);
    tutSave.setTexture(&Game::resourceManager.savePointTexture);
    tutTextSave.setFont(Game::resourceManager.font);
    tutTextSave.setCharacterSize(30);
    tutTextSave.setFillColor(sf::Color::Black);
    tutTextSave.setPosition(98, 360);
    tutTextSave.setString("< This is a save point. When touching one,\npress 'S' to save your progress.");
}

void Tutorial::tick()
{
    Game::camera.setPosition(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        //de-allocate stuff here
        Game::setState(Game::STATE_OVERWORLD);
    }
}

void Tutorial::draw(sf::RenderWindow& w)
{
    w.draw(tutHole);
    w.draw(tutWall);
    w.draw(tutSave);
    w.draw(tutTextHole);
    w.draw(tutTextWall);
    w.draw(tutTextSave);
}

Tutorial::~Tutorial()
{
    //dtor
}
