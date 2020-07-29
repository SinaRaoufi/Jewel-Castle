#ifndef BOARD_IG
#define BOARD_IG

#include <iostream>
#include <array>
#include "Tile.hpp"
#include "configs.hpp"

class Board
{
public:
    Board();
    void render(sf::RenderWindow &);

private:
    const size_t numberOfRow = NUM_OF_ROW;
    const size_t numberOfColumn = NUM_OF_COLUMN;
    std::array<std::array<Tile *, NUM_OF_COLUMN>, NUM_OF_ROW> listOfTiles;
};

#endif