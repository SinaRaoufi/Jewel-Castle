#include "States/PlayState.hpp"
#include "Move.hpp"
#include "Abilities/MagnetAbility.hpp"
#include "Abilities/FistAbility.hpp"
#include "Abilities/BombAbility.hpp"

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

enum abilityStates
{
    MAGNET,
    FIST,
    BOMB
};

short int abilityState = -1;

PlayState::PlayState() : gameScore(REQUIRED_SCORE)
{
    for (auto &ability : abilities)
        ability = nullptr;
    backgroundPath = "play_background.jpg";
    setBackground();
    abilities.at(MAGNET) = new MagnetAbility();
    abilities.at(MAGNET)->setPosition(270, 90);
    abilities.at(FIST) = new FistAbility();
    abilities.at(FIST)->setPosition(330, 90);
    abilities.at(BOMB) = new BombAbility();
    abilities.at(BOMB)->setPosition(390, 90);
}

GameState *PlayState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    abilities.at(2)->activateAbility();
    if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
            return state[MAINMENU];
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for (size_t i = MAGNET; i < NUM_OF_ABILITIES; i++)
                if (abilities[i])
                    if (abilities[i]->isAbilityActive())
                        if (abilities[i]->isAbilitySelected(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                            abilityState = i;

            for (size_t i = 0; i < gameBoard.getNumberOfRow(); i++)
                for (size_t j = 0; j < gameBoard.getNumberOfColumn(); j++)
                {
                    if (gameBoard.getListOfTiles()[i][j]->isTileSelected(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        if (abilityState != -1)
                        {
                            switch (abilityState)
                            {
                            case MAGNET:
                                gameBoard.removeRow(i);
                                abilities[MAGNET]->inactivateAbility();
                                abilityState = -1;
                                // score would be increase by each jewel's score plus 100
                                break;
                            case FIST:
                                gameBoard.removeRectangle(i, j);
                                abilities[FIST]->inactivateAbility();
                                abilityState = -1;
                                // score would be increase by each jewel's score plus 150
                                break;
                            case BOMB:
                                // gameBoard.removeRectangle(i, j);
                                abilities[BOMB]->inactivateAbility();
                                abilityState = -1;
                                // score would be increase by each jewel's score plus 200
                                break;
                            }
                            break;
                        }

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
                                scorePair p = gameBoard.refreshBoard();
                                for (const auto &item : p)
                                {
                                    cout << item.first << ' ' << item.second << endl;
                                    gameScore.increaseScore(item.first * item.second);
                                    switch (item.first)
                                    {
                                    case 4:
                                        abilities.at(0)->activateAbility();
                                        break;
                                    case 5:
                                        abilities.at(1)->activateAbility();
                                        break;
                                    case 6:
                                        abilities.at(2)->activateAbility();
                                        break;
                                    }
                                }
                                cout << gameScore.getCurrentScore() << '/' << gameScore.getRequiredScore() << endl;
                                // remember to set first and second to nullptr
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
    gameScore.render(window);
    for (const auto &ability : abilities)
        ability->render(window);
}