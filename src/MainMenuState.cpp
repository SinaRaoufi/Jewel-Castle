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
            if (state[PLAY] != nullptr)
                delete state[PLAY];
            state[PLAY] = new PlayState();
            return state[PLAY];
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