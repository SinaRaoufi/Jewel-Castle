#ifndef PLAY_STATE_IG
#define PLAY_STATE_IG

#include "States/GameState.hpp"
#include "Board.hpp"
#include "Score.hpp"
#include "Abilities/Ability.hpp"

class PlayState : public GameState
{
public:
    PlayState();
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) override;
    virtual GameState *update(sf::RenderWindow &, StateList &) override;
    virtual void render(sf::RenderWindow &) override;

private:
    Board gameBoard;
    Score gameScore;
    std::array<Ability *, NUM_OF_ABILITIES> abilities;
};

#endif