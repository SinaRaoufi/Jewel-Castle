#ifndef LOST_STATE_IG
#define LOST_STATE_IG

#include "States/GameState.hpp"
#include "Button.hpp"

class LostState : public GameState
{
public:
    LostState();
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) override;
    virtual GameState *update(sf::RenderWindow &, StateList &) override;
    virtual void render(sf::RenderWindow &) override;

private:
    Button restartButton;
    Button mainmenuButton;
};

#endif