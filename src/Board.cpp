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
    // initialize each element of listOfJewels to nullptr
    for (auto &row : listOfJewels)
        for (auto &item : row)
            item = nullptr;
    initial(listOfJewels);
    // Validate jewels combination
    while (!isJewelsCombinationValid())
        validateJewels();
    // Set tiles and jewels position
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

JewelList Board::getListOfJewels() const
{
    return listOfJewels;
}

// utility member function for generating random number
us Board::generateRandomNumber(us range1, us range2)
{
    random_device randomDevice;
    mt19937 mt(randomDevice());
    uniform_int_distribution<us> randomID(range1, range2);
    return randomID(mt);
}

// void Board::generateRandomJewels(Jewel *jewel)
// {
//     cout << "Done !" << endl;
//     if (jewel != nullptr)
//     {
//         // cout << "In" << endl;
//         delete jewel;
//     }
//     cout << "Done !" << endl;

//     switch (generateRandomNumber(YELLOW_JEWEL, VIOLET_JEWEL))
//     {
//     case YELLOW_JEWEL:
//         jewel = new YellowJewel();
//         break;
//     case GREEN_JEWEL:
//         jewel = new GreenJewel();
//         break;
//     case RED_JEWEL:
//         jewel = new RedJewel();
//         break;
//     case BLUE_JEWEL:
//         jewel = new BlueJewel();
//         break;
//     case PINK_JEWEL:
//         jewel = new PinkJewel();
//         break;
//     case VIOLET_JEWEL:
//         jewel = new VioletJewel();
//         break;
//     }
// }

Jewel *Board::generateRandomJewel()
{
    Jewel *jewel;
    switch (generateRandomNumber(YELLOW_JEWEL, VIOLET_JEWEL))
    {
    case YELLOW_JEWEL:
        jewel = new YellowJewel();
        break;
    case GREEN_JEWEL:
        jewel = new GreenJewel();
        break;
    case RED_JEWEL:
        jewel = new RedJewel();
        break;
    case BLUE_JEWEL:
        jewel = new BlueJewel();
        break;
    case PINK_JEWEL:
        jewel = new PinkJewel();
        break;
    case VIOLET_JEWEL:
        jewel = new VioletJewel();
        break;
    }
    return jewel;
}

void Board::initial(JewelList &listOfJewels)
{
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
            listOfJewels[i][j] = generateRandomJewel();
}

// Check jewels combination
bool Board::isJewelsCombinationValid() const
{
    // Check jewels horizontaly
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn - 1; j++)
            if (listOfJewels[i][j]->getJewelScore() == listOfJewels[i][j + 1]->getJewelScore())
            {
                if (j + 2 == numberOfColumn)
                    continue;
                if (listOfJewels[i][j + 1]->getJewelScore() == listOfJewels[i][j + 2]->getJewelScore())
                    return false;
            }
    // Check jewels verticaly
    for (size_t j = 0; j < numberOfColumn; j++)
        for (size_t i = 0; i < numberOfRow - 1; i++)
            if (listOfJewels[i][j]->getJewelScore() == listOfJewels[i + 1][j]->getJewelScore())
            {
                if (i + 2 == numberOfRow)
                    continue;
                if (listOfJewels[i + 1][j]->getJewelScore() == listOfJewels[i + 2][j]->getJewelScore())
                    return false;
            }
    return true;
}

void Board::validateJewels()
{
    // Validate jewels horizontaly
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn - 1; j++)
            if (listOfJewels[i][j]->getJewelScore() == listOfJewels[i][j + 1]->getJewelScore())
            {
                if (j + 2 == numberOfColumn)
                    continue;
                if (listOfJewels[i][j + 1]->getJewelScore() == listOfJewels[i][j + 2]->getJewelScore())
                {
                    delete listOfJewels[i][j + 1];
                    listOfJewels[i][j + 1] = generateRandomJewel();
                }
            }
    // Validate jewels verticaly
    for (size_t j = 0; j < numberOfColumn; j++)
        for (size_t i = 0; i < numberOfRow - 1; i++)
            if (listOfJewels[i][j]->getJewelScore() == listOfJewels[i + 1][j]->getJewelScore())
            {
                if (i + 2 == numberOfRow)
                    continue;
                if (listOfJewels[i + 1][j]->getJewelScore() == listOfJewels[i + 2][j]->getJewelScore())
                {
                    delete listOfJewels[i + 1][j];
                    listOfJewels[i + 1][j] = generateRandomJewel();
                }
            }
}