#include "States/PauseState.hpp"
#include <string>

using namespace std;

PauseState::PauseState() : resumeButton(BUTTON_TEXTURE_DIRECTORY + string("resume_button.png")),
                           exitButton(BUTTON_TEXTURE_DIRECTORY + string("exit_button.png"))
{
    backgroundPath = "pause_background.jpg";
    setBackground();
    this->resumeButton.setButtonPosition(235, 200);
    this->exitButton.setButtonPosition(235, 300);
}

GameState *PauseState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->resumeButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                return state[PLAY];
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->exitButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                return state[MAINMENU];
    return this;
}
GameState *PauseState::update(sf::RenderWindow &window, StateList &state)
{
    return this;
}
void PauseState::render(sf::RenderWindow &window)
{
    window.draw(this->backgroundSprite);
    this->resumeButton.render(window);
    this->exitButton.render(window);
}