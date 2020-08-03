#ifndef BOARD_IG
#define BOARD_IG

#include <iostream>
#include <array>
#include "Tile.hpp"
#include "Jewels/Jewel.hpp"
#include "configs.hpp"

typedef std::array<std::array<Tile *, NUM_OF_COLUMN>, NUM_OF_ROW> TileList;
typedef std::array<std::array<Jewel *, NUM_OF_COLUMN>, NUM_OF_ROW> JewelList;
typedef unsigned short int us;

class Board
{
public:
    Board();
    ~Board();
    size_t getNumberOfRow() const;
    size_t getNumberOfColumn() const;
    TileList getListOfTiles() const;
    JewelList getListOfJewels() const;
    void initial(JewelList &);
    // void generateRandomJewels(Jewel *);
    Jewel *generateRandomJewel();
    void render(sf::RenderWindow &);
    void swapTwoJewels(size_t, size_t, size_t, size_t);

private:
    const size_t numberOfRow = NUM_OF_ROW;
    const size_t numberOfColumn = NUM_OF_COLUMN;
    TileList listOfTiles;
    JewelList listOfJewels;
    us generateRandomNumber(us, us);       // utility member function for generating random number
    bool isJewelsCombinationValid() const; // utility member function for check jewels combination
    void validateJewels();                 // utility member function for validating jewels combination
};

#endif