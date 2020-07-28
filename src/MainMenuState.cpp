#include "States/MainMenuState.hpp"
#include "States/PlayState.hpp"
#include "configs.hpp"

using namespace std;

MainMenuState::MainMenuState() : playButton(100, 100, 200, 100,
                                            FONT_DIRECTORY + string("Xerox Sans Serif Narrow Bold.ttf"), "test")
{
    backgroundPath = "main_menu.png";
    setBackground();
}

GameState *MainMenuState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    // if (event.type == sf::Event::KeyPressed)
    //     if (event.key.code == sf::Keyboard::Space)
    //     {
    //         if (state[PLAY] != nullptr)
    //             delete state[PLAY];
    //         state[PLAY] = new PlayState();
    //         return state[PLAY];
    //     }
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (playButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
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
    playButton.render(window);
}