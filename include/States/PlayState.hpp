#ifndef PLAY_STATE_IG
#define PLAY_STATE_IG

#include "States/GameState.hpp"

class PlayState : public GameState
{
public:
PlayState();
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) override;
    virtual GameState *update(sf::RenderWindow &, StateList &) override;
    virtual void render(sf::RenderWindow &) override;
};

#endif