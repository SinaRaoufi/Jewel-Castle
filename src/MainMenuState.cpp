#include "States/MainMenuState.hpp"
#include "States/PlayState.hpp"
#include "configs.hpp"

using namespace std;

MainMenuState::MainMenuState() : playButton(BUTTON_TEXTURE_DIRECTORY + string("play_button.png")),
                                 exitButton(BUTTON_TEXTURE_DIRECTORY + string("exit_button.png"))
{
    playButton.setButtonPosition(250, 200);
    exitButton.setButtonPosition(250, 300);
    backgroundPath = "main_menu.jpg";
    setBackground();
}

GameState *MainMenuState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (playButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                if (state[PLAY] != nullptr)
                    delete state[PLAY];
                state[PLAY] = new PlayState();
                return state[PLAY];
            }
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (exitButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                window.close();
    return this;
}
GameState *MainMenuState::update(sf::RenderWindow &window, StateList &state)
{
    return this;
}
void MainMenuState::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    playButton.render(window);
    exitButton.render(window);
}