#include "Game.hpp"
#include "States/PauseState.hpp"
#include "States/MainMenuState.hpp"
#include "States/WinState.hpp"
#include "States/LostState.hpp"

Game::Game() : mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE,sf::Style::Close), currentState(nullptr)
{
    this->mainWindow.requestFocus();
    for (size_t i = 0; i < NUMBER_OF_STATES; i++)
        statesList[i] = nullptr;
}

// initialize the game
void Game::init()
{
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