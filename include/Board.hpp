#ifndef BOARD_IG
#define BOARD_IG

#include <iostream>
#include <array>
#include <vector>
#include "Tile.hpp"
#include "Jewels/Jewel.hpp"
#include "configs.hpp"

typedef std::array<std::array<Tile *, NUM_OF_COLUMN>, NUM_OF_ROW> TileList;
typedef std::array<std::array<Jewel *, NUM_OF_COLUMN>, NUM_OF_ROW> JewelList;
typedef unsigned short int us;
typedef std::vector<std::pair<us, us>> scorePair;

class Board
{
public:
    Board();
    ~Board();
    size_t getNumberOfRow() const;
    size_t getNumberOfColumn() const;
    TileList getListOfTiles() const;
    JewelList getListOfJewels() const;
    void shuffleJewels(JewelList &);
    Jewel *generateRandomJewel();
    void render(sf::RenderWindow &);
    void swapTwoJewels(size_t, size_t, size_t, size_t, sf::RenderWindow &);
    scorePair refreshBoard();
    unsigned int removeRow(size_t);
    unsigned int removeRectangle(size_t, size_t);
    unsigned int removeThreeRowColumn(size_t, size_t);

private:
    const size_t numberOfRow = NUM_OF_ROW;
    const size_t numberOfColumn = NUM_OF_COLUMN;
    TileList listOfTiles;
    JewelList listOfJewels;
    bool isJewelsCombinationValid() const; // utility member function for check jewels combination
    void validateJewels();                 // utility member function for validating jewels combination
};

#endif