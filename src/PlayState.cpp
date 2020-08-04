#include "States/PlayState.hpp"
#include "Move.hpp"

#include <iostream>
using namespace std;
struct ChoosenEntity
{
    Jewel *choosenJewel = nullptr;
    Tile *choosenTile = nullptr;
    size_t iPosition;
    size_t jPosition;
};

struct ChoosenEntity first;
struct ChoosenEntity second;

PlayState::PlayState()
{
    backgroundPath = "play_background.jpg";
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
                    {
                        if (first.choosenJewel == nullptr)
                        {
                            first.choosenJewel = gameBoard.getListOfJewels()[i][j];
                            first.iPosition = i;
                            first.jPosition = j;
                            first.choosenTile = gameBoard.getListOfTiles()[i][j];
                            first.choosenTile->setTileColor(sf::Color::Green);
                            break;
                        }
                        if (first.iPosition == i && first.jPosition - 1 == j ||
                            first.iPosition == i && first.jPosition + 1 == j ||
                            first.iPosition + 1 == i && first.jPosition == j ||
                            first.iPosition - 1 == i && first.jPosition == j)
                        {
                            second.choosenJewel = gameBoard.getListOfJewels()[i][j];
                            second.choosenTile = gameBoard.getListOfTiles()[i][j];
                            second.choosenTile->setTileColor(sf::Color::Black);
                            second.iPosition = i;
                            second.jPosition = j;
                            if (isMoveValid(gameBoard, first.iPosition, first.jPosition, second.iPosition, second.jPosition))
                            {
                                gameBoard.swapTwoJewels(first.iPosition, first.jPosition, second.iPosition, second.jPosition);
                                gameBoard.refreshBoard();
                            }
                        }
                        else
                        {
                            first.choosenTile->setTileColor(sf::Color(216, 191, 216));
                            if (second.choosenTile != nullptr)
                                second.choosenTile->setTileColor(sf::Color(216, 191, 216));
                            first.choosenJewel = gameBoard.getListOfJewels()[i][j];
                            first.iPosition = i;
                            first.jPosition = j;
                            first.choosenTile = gameBoard.getListOfTiles()[i][j];
                            first.choosenTile->setTileColor(sf::Color::Green);
                        }
                    }
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