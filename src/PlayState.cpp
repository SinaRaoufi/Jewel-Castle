#include "States/PlayState.hpp"
#include "Move.hpp"
#include "Abilities/MagnetAbility.hpp"
#include "Abilities/FistAbility.hpp"
#include "Abilities/BombAbility.hpp"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <pwd.h>

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

short int abilityState = NONE;

PlayState::PlayState() : gameScore(REQUIRED_SCORE), gameTimer(TIMER_COUNTDOWN), gameMove(NUM_OF_MOVE),
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
    gameMove.setMoveProgressBarPosition(628, 142);
}

PlayState::~PlayState()
{
    // delete each ability that allocated dynamically
    for (auto &ability : abilities)
        delete ability;
}

GameState *PlayState::eventHandler(sf::RenderWindow &window, StateList &state, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (this->pauseButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                return state[PAUSE];

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
                            break;
                        }

                        if (first.choosenJewel == nullptr)
                        {
                            first.choosenJewel = gameBoard.getListOfJewels()[i][j];
                            first.iPosition = i;
                            first.jPosition = j;
                            first.choosenTile = gameBoard.getListOfTiles()[i][j];
                            first.choosenTile->enableTileOutline();
                            break;
                        }
                        else if (first.iPosition == i && first.jPosition - 1 == j ||
                                 first.iPosition == i && first.jPosition + 1 == j ||
                                 first.iPosition + 1 == i && first.jPosition == j ||
                                 first.iPosition - 1 == i && first.jPosition == j)
                        {
                            second.choosenJewel = gameBoard.getListOfJewels()[i][j];
                            second.choosenTile = gameBoard.getListOfTiles()[i][j];
                            second.iPosition = i;
                            second.jPosition = j;
                            second.choosenTile->enableTileOutline();
                            if (gameMove.isMoveValid(gameBoard, first.iPosition, first.jPosition, second.iPosition, second.jPosition))
                            {
                                gameBoard.swapTwoJewels(first.iPosition, first.jPosition, second.iPosition, second.jPosition, window);
                                scorePair p = gameBoard.refreshBoard();
                                for (const auto &item : p)
                                {
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
                                gameMove.decreaseNumberOfMoveByOne();
                            }
                            first.choosenTile->disableTileOutline();
                            first.choosenJewel = nullptr;
                            second.choosenTile->disableTileOutline();
                            second.choosenJewel = nullptr;
                        }
                        else if (first.iPosition != i || first.jPosition != j)
                        {
                            first.choosenTile->disableTileOutline();
                            first.choosenJewel = gameBoard.getListOfJewels()[i][j];
                            first.iPosition = i;
                            first.jPosition = j;
                            first.choosenTile = gameBoard.getListOfTiles()[i][j];
                            first.choosenTile->enableTileOutline();
                        }
                    }
                }
        }
    return this;
}

GameState *PlayState::update(sf::RenderWindow &window, StateList &state)
{
    gameTimer.updateTime();
    if (gameTimer.getCountDownTime() < 0)
    {
        saveGameInformations();
        return state[LOST];
    }
    if (gameScore.getCurrentScore() >= gameScore.getRequiredScore())
    {
        saveGameInformations();
        return state[WIN];
    }
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
    gameMove.render(window);
}

void PlayState::saveGameInformations() const
{
    ofstream file;
    file.open(DATA_DIRECTORY + string("game_data.txt"), ios::app);
    file << getpwuid(getuid())->pw_name << endl;
    file << gameScore.getCurrentScore() << endl;
    file.close();
}