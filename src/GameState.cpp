#include "States/GameState.hpp"
#include "configs.hpp"

void GameState::setBackground()
{
    std::string address = std::string(BACKGROUND_DIRECTORY) + backgroundPath;
    backgroundTexture.loadFromFile(address);
    backgroundSprite.setTexture(backgroundTexture);
}