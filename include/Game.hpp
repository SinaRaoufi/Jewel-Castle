#ifndef GAME_IG
#define GAME_IG

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void Init();

private:
    sf::RenderWindow mainWindow;
};

#endif