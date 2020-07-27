#include "States/PlayState.hpp"

PlayState::PlayState()
{
    backgroundPath = "play_background.png";
    setBackground();
}

GameState *PlayState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
            return state[MAINMENU];
    return this;
}

GameState *PlayState::update(sf::RenderWindow &window, StateList &state)
{
    return this;
}

void PlayState::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
}