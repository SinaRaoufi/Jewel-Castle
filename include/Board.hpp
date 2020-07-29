#ifndef BOARD_IG
#define BOARD_IG

#include <iostream>
#include <array>
#include "Tile.hpp"
#include "configs.hpp"

typedef std::array<std::array<Tile *, NUM_OF_COLUMN>, NUM_OF_ROW> TileList;

class Board
{
public:
    Board();
    ~Board();
    size_t getNumberOfRow() const;
    size_t getNumberOfColumn() const;
    TileList getListOfTiles() const;
    void render(sf::RenderWindow &);

private:
    const size_t numberOfRow = NUM_OF_ROW;
    const size_t numberOfColumn = NUM_OF_COLUMN;
    TileList listOfTiles;
};

#endif