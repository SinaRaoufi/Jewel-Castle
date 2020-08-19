#include "Game.hpp"
#include "States/PauseState.hpp"
#include "States/MainMenuState.hpp"
#include "States/WinState.hpp"
#include "States/LostState.hpp"

Game::Game() : mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close), currentState(nullptr)
{
    // centralized the game window
    this->mainWindow.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - mainWindow.getSize().x / 2,
                                              sf::VideoMode::getDesktopMode().height / 2 - mainWindow.getSize().y / 2));
    this->mainWindow.requestFocus();
    // initialized each states to nullptr
    for (size_t i = 0; i < NUMBER_OF_STATES; i++)
        statesList[i] = nullptr;
}

// initialized the game
void Game::init()
{
    // creates each game state that we need in the game (except PlayState)
    statesList[MAINMENU] = new MainMenuState();
    statesList[PAUSE] = new PauseState();
    statesList[WIN] = new WinState();
    statesList[LOST] = new LostState();
    currentState = statesList[MAINMENU];
    run();
}

// game loop
void Game::run()
{
    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
            currentState = currentState->eventHandler(mainWindow, statesList, event);
        }
        currentState = currentState->update(mainWindow, statesList);
        mainWindow.clear();
        currentState->render(mainWindow);
        mainWindow.display();
    }
}