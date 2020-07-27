#include "States/MainMenuState.hpp"

using namespace std;

MainMenuState::MainMenuState()
{
    backgroundPath = "main_menu.png";
    setBackground();
}

GameState *MainMenuState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    return this;
}
GameState *MainMenuState::update(sf::RenderWindow &window, StateList &state)
{
    return this;
}
void MainMenuState::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
}