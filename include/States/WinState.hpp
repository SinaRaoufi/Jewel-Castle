#ifndef WIN_STATE_IG
#define WIN_STATE_IG

#include "States/GameState.hpp"
#include "Button.hpp"

class WinState : public GameState
{
public:
    WinState();
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) override;
    virtual GameState *update(sf::RenderWindow &, StateList &) override;
    virtual void render(sf::RenderWindow &) override;

private:
    Button restartButton;
    Button mainmenuButton;
};

#endif