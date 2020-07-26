#ifndef GAME_IG
#define GAME_IG

#include <SFML/Graphics.hpp>
#include "configs.hpp"
#include "States/GameState.hpp"
#include <array>

typedef std::array<GameState*,NUMBER_OF_STATES> StateList;

class Game
{
public:
    Game();
    void init();

private:
    sf::RenderWindow mainWindow;
    GameState* currentState;
    StateList statesList;

};

#endif