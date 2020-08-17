#include "States/LostState.hpp"
#include "States/PlayState.hpp"
#include <string>

using namespace std;

LostState::LostState() : restartButton(BUTTON_TEXTURE_DIRECTORY + string("restart_circle_button.png")),
                         mainmenuButton(BUTTON_TEXTURE_DIRECTORY + string("mainmenu_circle_button.png"))
{
    backgroundPath = "lost_background.jpg";
    setBackground();
    this->restartButton.setButtonPosition(255, 350);
    this->mainmenuButton.setButtonPosition(355, 354);
}

GameState *LostState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    // checks whether the restart button is selected or not
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->restartButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                delete state[PLAY];
                state[PLAY] = new PlayState();
                return state[PLAY];
            }
    // checks whether the main menu button is selected or not
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->mainmenuButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                delete state[PLAY];
                state[PLAY] = nullptr;
                return state[MAINMENU];
            }
    return this;
}

GameState *LostState::update(sf::RenderWindow &window, StateList &state)
{
    return this;
}

void LostState::render(sf::RenderWindow &window)
{
    window.draw(this->backgroundSprite);
    this->restartButton.render(window);
    this->mainmenuButton.render(window);
}