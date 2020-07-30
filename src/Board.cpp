#include <Board.hpp>
#include <ctime>
#include <random>
#include <SFML/Graphics.hpp>

#include "Jewels/YellowJewel.hpp"
#include "Jewels/GreenJewel.hpp"
#include "Jewels/RedJewel.hpp"
#include "Jewels/BlueJewel.hpp"
#include "Jewels/PinkJewel.hpp"
#include "Jewels/VioletJewel.hpp"

using namespace std;

Board::Board()
{
    generateRandomJewels(listOfJewels);
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
        {
            sf::Color tileColor(216, 191, 216);
            listOfTiles[i][j] = new Tile(Tile_WIDTH, Tile_HEIGHT, tileColor, sf::Color::Black);
            listOfTiles[i][j]->setTilePosition(j * Tile_WIDTH + 150, Tile_HEIGHT * i + 150);
            listOfJewels[i][j]->setJewelPosition(j * Tile_WIDTH + 150, Tile_HEIGHT * i + 150);
        }
}

Board::~Board()
{
    // delete each tile
    for (auto &row : listOfTiles)
        for (auto &item : row)
            delete item;

    //delete each jewel
    for (auto &row : listOfJewels)
        for (auto &item : row)
            delete item;
}

void Board::render(sf::RenderWindow &window)
{
    for (auto row : listOfTiles)
        for (auto item : row)
            item->render(window);

    for (auto row : listOfJewels)
        for (auto item : row)
            item->render(window);
}

size_t Board::getNumberOfRow() const
{
    return this->numberOfRow;
}

size_t Board::getNumberOfColumn() const
{
    return this->numberOfColumn;
}

TileList Board::getListOfTiles() const
{
    return listOfTiles;
}

// utility member function for generating random number
us Board::generateRandomNumber(us range1, us range2)
{
    random_device randomDevice;
    mt19937 mt(randomDevice());
    uniform_int_distribution<us> randomID(range1, range2);
    return randomID(mt);
}

void Board::generateRandomJewels(JewelList &listOfJewels)
{
    enum JewelsEnum
    {
        YELLOW_JEWEL,
        GREEN_JEWEL,
        RED_JEWEL,
        BLUE_JEWEL,
        PINK_JEWEL,
        VIOLET_JEWEL
    };
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
        {
            switch (generateRandomNumber(YELLOW_JEWEL, VIOLET_JEWEL))
            {
            case YELLOW_JEWEL:
                listOfJewels[i][j] = new YellowJewel();
                break;
            case GREEN_JEWEL:
                listOfJewels[i][j] = new GreenJewel();
                break;
            case RED_JEWEL:
                listOfJewels[i][j] = new RedJewel();
                break;
            case BLUE_JEWEL:
                listOfJewels[i][j] = new BlueJewel();
                break;
            case PINK_JEWEL:
                listOfJewels[i][j] = new PinkJewel();
                break;
            case VIOLET_JEWEL:
                listOfJewels[i][j] = new VioletJewel();
                break;
            }
        }
}