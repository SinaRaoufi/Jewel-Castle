#include "States/PlayState.hpp"

PlayState::PlayState()
{
    backgroundPath = "play_background.png";
    setBackground();
}

GameState *PlayState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
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