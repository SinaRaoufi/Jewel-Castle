#ifndef GAME_STATE_IG
#define GAME_STATE_IG

#include <SFML/Graphics.hpp>
#include "configs.hpp"
#include <array>
#include <string>

enum States
{
    MAINMENU,
    PLAY,
    PAUSE,
    WIN,
    LOST
};

class GameState
{
public:
    typedef std::array<GameState *, NUMBER_OF_STATES> StateList;
    virtual GameState *eventHandler(sf::RenderWindow &, StateList &, sf::Event &) = 0;
    virtual GameState *update(sf::RenderWindow &, StateList &) = 0;
    virtual void render(sf::RenderWindow &) = 0;
    void setBackground();

protected:
    std::string backgroundPath;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};

#endif