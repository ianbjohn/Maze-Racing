#include "Game.h"

bool Game::newGame;
int Game::state;
int Game::stateOld;
int Game::levelNum;
int Game::levelNumOld;
int Game::saveFileIndex;
const sf::Color Game::backgroundColors[NUM_GAMESTATES] = {sf::Color::Blue, sf::Color::Blue, sf::Color(192, 192, 192), sf::Color(0, 192, 192), sf::Color(192, 192, 192), sf::Color(192, 192, 192), sf::Color::Black};
ResourceManager Game::resourceManager;
std::fstream Game::gameFile;
const char* Game::saveFileNames[NUM_SAVEFILES] = {"savefile0.sav", "savefile1.sav", "savefile2.sav"};
SaveFile Game::saveFiles[NUM_SAVEFILES] = {{20, 90, 0}, {20, 190, 1}, {20, 290, 2}};
sf::RectangleShape Game::titleRect;
Overworld Game::overworld;
Level Game::level;
Camera Game::camera;
Tutorial Game::tutorial;
LevelShip Game::levelShip;
OverworldShip Game::overworldShip;
sf::RenderWindow Game::window{sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Racing"};
sf::Event Game::event;

Game::Game()
{
    window.setIcon(32, 32, Game::resourceManager.holeTexture.copyToImage().getPixelsPtr());

    state = STATE_TITLE;
    stateOld = state;

    titleRect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    titleRect.setPosition(0, 0);
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

        window.clear(backgroundColors[state]);
        //maybe in future projects have the entity list just in the game class? and draw whichever entities are currently active
        switch (state) {
        case STATE_TITLE:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                //load a new game (TEMPORARY)
                newGame = true;

                resourceManager.titleSong.stop();
                state = STATE_FILESELECT;
            }

            window.draw(titleRect);

            break;
        case STATE_FILESELECT:
            for (int i = 0; i < NUM_SAVEFILES; i++) {
                saveFiles[i].tick();
                saveFiles[i].draw(window);
            }

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

            camera.draw(window);
            break;
        case STATE_TUTORIAL:
            tutorial.tick();
            tutorial.draw(window);
            camera.draw(window);
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

            camera.draw(window);
            break;
        }

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

int Game::getSaveFileIndex()
{
    return saveFileIndex;
}

void Game::setState(int s)
{
    state = s;
}

void Game::setLevelNum(int l)
{
    levelNum = l;
}

void Game::setOldLevelNum(int l)
{
    levelNumOld = l;
}

void Game::updateOldState()
{
    stateOld = state;
}

void Game::updateOldLevelNum()
{
    levelNumOld = levelNum;
}

void Game::setSaveFileIndex(int i)
{
    saveFileIndex = i;
}

void Game::loadTutorial()
{

}

Game::~Game()
{
    //dtor
}
