#include "States/GameState.hpp"
#include "configs.hpp"

using namespace std;

void GameState::setBackground()
{
    string address = string(BACKGROUND_DIRECTORY) + backgroundPath;
    backgroundTexture.loadFromFile(address);
    backgroundSprite.setTexture(backgroundTexture);
}