#include "States/PlayState.hpp"

PlayState::PlayState()
{
    backgroundPath = "play.png";
    setBackground();
}

GameState *PlayState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
            return state[MAINMENU];
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for (size_t i = 0; i < gameBoard.getNumberOfRow(); i++)
                for (size_t j = 0; j < gameBoard.getNumberOfColumn(); j++)
                {
                    if (gameBoard.getListOfTiles()[i][j]->isTileSelected(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        gameBoard.getListOfTiles()[i][j]->setTileColor(sf::Color::Green);
                }
        }

    return this;
}

GameState *PlayState::update(sf::RenderWindow &window, StateList &state)
{
    return this;
}

void PlayState::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    gameBoard.render(window);
}