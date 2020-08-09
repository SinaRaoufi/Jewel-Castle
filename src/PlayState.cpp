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
    NONE = -1,
    MAGNET,
    FIST,
    BOMB
};

short int abilityState = NONE;

PlayState::PlayState() : gameScore(REQUIRED_SCORE), numberOfMove(NUM_OF_MOVE), gameTimer(TIMER_COUNTDOWN),
                         pauseButton(BUTTON_TEXTURE_DIRECTORY + string("pause_button.png"))
{
    // initialize each elements to nullptr
    for (auto &ability : abilities)
        ability = nullptr;
    backgroundPath = "play_background.jpg";
    setBackground();
    pauseButton.setButtonPosition(0, 0);
    abilities[MAGNET] = new MagnetAbility();
    abilities[MAGNET]->setPosition(265, 90);
    abilities[FIST] = new FistAbility();
    abilities[FIST]->setPosition(325, 90);
    abilities[BOMB] = new BombAbility();
    abilities[BOMB]->setPosition(385, 90);
    gameScore.setScoreProgressBarPosition(530, 0);
    gameTimer.setTimerProgressBarPosition(560, 70);
}

PlayState::~PlayState()
{
    for (auto &ability : abilities)
        delete ability;
}

GameState *PlayState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (this->pauseButton.isButtonPressed(sf::Vector2f(event.mouseButton.x,event.mouseButton.y)))
            {
                return state[PAUSE];
            }
            
            // checks whether the ability is selected or not
            for (size_t i = MAGNET; i < NUM_OF_ABILITIES; i++)
                if (abilities[i]->isAbilityActive())
                    if (abilities[i]->isAbilitySelected(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        abilityState = i;

            // checks whether the tile is selected or not
            for (size_t i = 0; i < gameBoard.getNumberOfRow(); i++)
                for (size_t j = 0; j < gameBoard.getNumberOfColumn(); j++)
                {
                if (gameBoard.getListOfTiles()[i][j]->isTileSelected(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    if (abilityState != NONE)
                    {
                        unsigned int score;
                        switch (abilityState)
                        {
                        case MAGNET:
                        {
                            score = gameBoard.removeRow(i);
                            abilities[MAGNET]->inactivateAbility();
                            gameScore.increaseScore(score + 100);
                            break;
                        }
                        case FIST:
                        {
                            score = gameBoard.removeRectangle(i, j);
                            abilities[FIST]->inactivateAbility();
                            gameScore.increaseScore(score + 150);
                            break;
                        }
                        case BOMB:
                            score = gameBoard.removeThreeRowColumn(i, j);
                            abilities[BOMB]->inactivateAbility();
                            gameScore.increaseScore(score + 200);
                            break;
                        }
                        abilityState = NONE;
                        numberOfMove--;
                        break;
                    }

                    if (first.choosenJewel == nullptr)
                    {
                        first.choosenJewel = gameBoard.getListOfJewels()[i][j];
                        first.iPosition = i;
                        first.jPosition = j;
                        first.choosenTile = gameBoard.getListOfTiles()[i][j];
                        first.choosenTile->setTileColor(sf::Color(255, 69, 0));
                        break;
                    }
                    else if (first.iPosition == i && first.jPosition - 1 == j ||
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
                                    abilities[MAGNET]->activateAbility();
                                    break;
                                case 5:
                                    abilities[FIST]->activateAbility();
                                    break;
                                case 6:
                                    abilities[BOMB]->activateAbility();
                                    break;
                                }
                            }
                            cout << gameScore.getCurrentScore() << '/' << gameScore.getRequiredScore() << endl;
                            numberOfMove--;
                        }
                        gameBoard.getListOfTiles()[first.iPosition][first.jPosition]->resetTileColorToDefualt();
                        first.choosenJewel = nullptr;
                        gameBoard.getListOfTiles()[second.iPosition][second.jPosition]->resetTileColorToDefualt();
                        second.choosenJewel = nullptr;
                    }
                    else if (first.iPosition != i || first.jPosition != j)
                    {
                        first.choosenTile->resetTileColorToDefualt();
                        first.choosenJewel = gameBoard.getListOfJewels()[i][j];
                        first.iPosition = i;
                        first.jPosition = j;
                        first.choosenTile = gameBoard.getListOfTiles()[i][j];
                        first.choosenTile->setTileColor(sf::Color(255, 69, 0));
                    }
                }
                }
        }
    return this;
}

GameState *PlayState::update(sf::RenderWindow &window, StateList &state)
{
    gameTimer.updateTime();
    if(gameScore.getCurrentScore() >=gameScore.getRequiredScore())
        return state[WIN];
    return this;
}

void PlayState::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    gameBoard.render(window);
    gameScore.render(window);
    for (const auto &ability : abilities)
        ability->render(window);
    gameTimer.render(window);
    pauseButton.render(window);
}