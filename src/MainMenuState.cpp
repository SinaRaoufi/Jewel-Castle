#include "States/MainMenuState.hpp"
#include "States/PlayState.hpp"

using namespace std;

MainMenuState::MainMenuState()
{
    backgroundPath = "main_menu.png";
    setBackground();
}

GameState *MainMenuState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Space)
        {
            if (state[1] != nullptr)
                delete state[1];
            state[1] = new PlayState();
            return state[1];
        }
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