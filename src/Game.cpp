#include "Game.h"

bool Game::newGame;
int Game::state;
int Game::stateOld;
int Game::levelNum;
int Game::levelNumOld;
ResourceManager Game::resourceManager;
std::fstream Game::gameFile;
sf::RectangleShape Game::titleRect;
Overworld Game::overworld;
Level Game::level;
Camera Game::camera;
LevelShip Game::levelShip;
OverworldShip Game::overworldShip;
sf::RenderWindow Game::window{sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racing"};
sf::Event Game::event;

Game::Game()
{
    window.setIcon(32, 32, Game::resourceManager.holeTexture.copyToImage().getPixelsPtr());

    state = STATE_TITLE;
    stateOld = state;

    resourceManager.titleTexture.loadFromFile("gfx/title.png");
    titleRect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    titleRect.setPosition(-(SCREEN_WIDTH / 2), -(SCREEN_HEIGHT / 2));
    titleRect.setTexture(&resourceManager.titleTexture);
    resourceManager.titleSong.play();

    window.setFramerateLimit(60);
}

void Game::run()
{
    //once more comfortable with function pointers, have an array of pointers to each state function
    //like an indirect jump table
    //just to get rid of some of these parentheses
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(192, 192, 192));

        //maybe in future projects have the entity list just in the game class? and draw whichever entities are currently active
        switch (state) {
        case STATE_TITLE:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                //load a new game (TEMPORARY)
                newGame = true;

                resourceManager.titleSong.stop();
                levelNum = 0;
                levelNumOld = 0;
                level.load();
                overworld.load();
                state = STATE_OVERWORLD;
            }

            window.draw(titleRect);

            break;
        case STATE_OVERWORLD:
            if (overworldShip.getState() == OverworldShip::STATE_EXPLODING) {
                overworldShip.setPosition(overworldShip.getReturnX(), overworldShip.getReturnY());
                camera.follow(overworldShip, overworld);
                for (int i = overworld.getReturnHoleIndex(); i < NUM_HOLES; i++)
                    overworld.getHole(i)->setState(Hole::STATE_OPEN);
                overworldShip.setState(OverworldShip::STATE_STILL);
                level.cleanUpScreen();
                setLevelNum(overworld.getReturnHoleIndex());
                level.load();
            }

            overworldShip.tick();
            overworld.tick();
            camera.follow(overworldShip, Game::overworld);
            overworld.drawScreen(window);
            overworldShip.draw(window);

            //if the ship hit a hole, go to the level

            break;
        case STATE_LEVEL:
            levelShip.tick();
            camera.follow(levelShip, level);
            level.drawScreen(window);
            levelShip.draw(window);

            if (levelShip.getState() == LevelShip::STATE_EXPLODING) {
                overworldShip.setPosition(overworldShip.getReturnX(), overworldShip.getReturnY());
                camera.follow(overworldShip, overworld);
                state = STATE_OVERWORLD;
                for (int i = overworld.getReturnHoleIndex(); i < NUM_HOLES; i++)
                    overworld.getHole(i)->setState(Hole::STATE_OPEN);
                overworldShip.setState(OverworldShip::STATE_STILL);
                level.cleanUpScreen();
                setLevelNum(overworld.getReturnHoleIndex());
                level.load();
            } else if (getLevelNum() != getOldLevelNum()) {
                //load new level if the player finished the current level
                updateOldLevelNum();
                level.cleanUpScreen();
                level.load();
                state = STATE_OVERWORLD;
            }

            break;
        }

        camera.draw(window);
        window.display();
    }
}

bool Game::checkIfNewGame()
{
    return newGame;
}

int Game::getState()
{
    return state;
}

int Game::getOldState()
{
    return stateOld;
}

int Game::getLevelNum()
{
    return levelNum;
}

int Game::getOldLevelNum()
{
    return levelNumOld;
}

void Game::setState(int s)
{
    state = s;
}

void Game::setLevelNum(int l)
{
    levelNum = l;
}

void Game::updateOldState()
{
    stateOld = state;
}

void Game::updateOldLevelNum()
{
    levelNumOld = levelNum;
}

Game::~Game()
{
    //dtor
}
