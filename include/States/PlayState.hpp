#ifndef PLAY_STATE_IG
#define PLAY_STATE_IG

#include "States/GameState.hpp"
#include "Board.hpp"
#include "Score.hpp"
#include "Timer.hpp"
#include "Button.hpp"
#include "Move.hpp"
#include "Abilities/Ability.hpp"

class PlayState : public GameState
{
public:
    PlayState();
    ~PlayState();
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) override;
    virtual GameState *update(sf::RenderWindow &, StateList &) override;
    virtual void render(sf::RenderWindow &) override;

private:
    Board gameBoard;
    Score gameScore;
    Timer gameTimer;
    Move gameMove;
    std::array<Ability *, NUM_OF_ABILITIES> abilities;
    Button pauseButton;
    void saveGameInformations() const;
};

#endif