#include "Game.hpp"

Game::Game() : mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), currentState(nullptr)
{
    for (size_t i = 0; i < NUMBER_OF_STATES; i++)
        statesList[i] = nullptr;
}

// initialize the game
void Game::init()
{
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
    }
}