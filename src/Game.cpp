#include "Game.hpp"

Game::Game() : mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), currentState(nullptr)
{
    for (size_t i = 0; i < NUMBER_OF_STATES; i++)
        statesList[i] = nullptr;
}

// initialize the game
void Game::init()
{
}