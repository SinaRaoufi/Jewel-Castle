#ifndef PAUSE_STATE_IG
#define PAUSE_STATE_IG

#include "States/GameState.hpp"
#include "Button.hpp"

class PauseState : public GameState
{
public:
    PauseState();
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) override;
    virtual GameState *update(sf::RenderWindow &, StateList &) override;
    virtual void render(sf::RenderWindow &) override;

private:
    Button resumeButton;
    Button restartButton;
    Button exitButton;
};

#endif