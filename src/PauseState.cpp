#include "States/PauseState.hpp"
#include "States/PlayState.hpp"
#include <string>

using namespace std;

PauseState::PauseState() : resumeButton(BUTTON_TEXTURE_DIRECTORY + string("resume_button.png")),
                           exitButton(BUTTON_TEXTURE_DIRECTORY + string("exit_button.png")),
                           restartButton(BUTTON_TEXTURE_DIRECTORY + string("restart_button.png"))
{
    backgroundPath = "pause_background.jpg";
    setBackground();
    this->resumeButton.setButtonPosition(235, 200);
    this->restartButton.setButtonPosition(235, 300);
    this->exitButton.setButtonPosition(235, 385);
}

GameState *PauseState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    // checks whether the resume button is selected or not
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->resumeButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                return state[PLAY];
    // checks whether the exit button is selected or not
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->exitButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                return state[MAINMENU];
    // checks whether the restart button is selected or not
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (this->restartButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                delete state[PLAY];
                state[PLAY] = new PlayState();
                return state[PLAY];
            }
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
    this->restartButton.render(window);
    this->exitButton.render(window);
}