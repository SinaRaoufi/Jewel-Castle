#include <Board.hpp>
#include <ctime>
#include <random>
#include <vector>
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

void Board::swapTwoJewels(size_t i1, size_t j1, size_t i2, size_t j2)
{
    listOfJewels[i1][j1]->setJewelPosition(j2 * Tile_WIDTH + 150, Tile_HEIGHT * i2 + 150);
    listOfJewels[i2][j2]->setJewelPosition(j1 * Tile_WIDTH + 150, Tile_HEIGHT * i1 + 150);
    swap(listOfJewels[i1][j1], listOfJewels[i2][j2]);
}

scorePair Board::refreshBoard()
{
    us numberOfDeletedJewel = 0;
    scorePair p;
    while (!isJewelsCombinationValid())
    {
        // Refresh game board horizontaly
        for (int i = numberOfRow - 1; i != -1; i--)
            for (size_t j = 0; j < numberOfColumn - 1; j++)
            {
                if (j + 1 != numberOfColumn)
                    if (listOfJewels[i][j]->getJewelScore() == listOfJewels[i][j + 1]->getJewelScore() &&
                        listOfJewels[i][j + 1]->getJewelScore() == listOfJewels[i][j + 2]->getJewelScore())
                    {
                        us jewelScore = listOfJewels[i][j]->getJewelScore();
                        size_t k = j;
                        while (listOfJewels[i][k]->getJewelScore() == jewelScore)
                        {
                            if (k == numberOfColumn)
                                break;
                            delete listOfJewels[i][k];
                            if (i != 0)
                                for (int f = i - 1; f != -1; f--) // could be a single function (Use DRY principle)
                                {
                                    listOfJewels[f + 1][k] = listOfJewels[f][k];
                                    listOfJewels[f + 1][k]->setJewelPosition(k * Tile_WIDTH + 150, Tile_HEIGHT * (f + 1) + 150);
                                }
                            listOfJewels[0][k] = generateRandomJewel();
                            while (listOfJewels[0][k]->getJewelScore() == jewelScore)
                            {
                                delete listOfJewels[0][k];
                                listOfJewels[0][k] = generateRandomJewel();
                            }
                            listOfJewels[0][k]->setJewelPosition(k * Tile_WIDTH + 150, Tile_HEIGHT * 0 + 150);
                            k++;
                            numberOfDeletedJewel++;
                        }
                        p.push_back(make_pair(numberOfDeletedJewel, jewelScore));
                        numberOfDeletedJewel = 0;
                    }
            }
        for (size_t j = 0; j < numberOfColumn; j++)
            for (int i = numberOfRow - 1; i > 0; i--)
            {
                if (i - 1 != 0)
                    if (listOfJewels[i][j]->getJewelScore() == listOfJewels[i - 1][j]->getJewelScore() &&
                        listOfJewels[i - 1][j]->getJewelScore() == listOfJewels[i - 2][j]->getJewelScore())
                    {
                        us jewelScore = listOfJewels[i][j]->getJewelScore();
                        while (listOfJewels[i][j]->getJewelScore() == jewelScore)
                        {
                            delete listOfJewels[i][j];
                            for (int f = i - 1; f != -1; f--) // could be a single function (Use DRY principle)
                            {
                                listOfJewels[f + 1][j] = listOfJewels[f][j];
                                listOfJewels[f + 1][j]->setJewelPosition(j * Tile_WIDTH + 150, Tile_HEIGHT * (f + 1) + 150);
                            }
                            listOfJewels[0][j] = generateRandomJewel();
                            while (listOfJewels[0][j]->getJewelScore() == jewelScore)
                            {
                                delete listOfJewels[0][j];
                                listOfJewels[0][j] = generateRandomJewel();
                            }
                            listOfJewels[0][j]->setJewelPosition(j * Tile_WIDTH + 150, Tile_HEIGHT * 0 + 150);
                            numberOfDeletedJewel++;
                        }
                        p.push_back(make_pair(numberOfDeletedJewel, jewelScore));
                        numberOfDeletedJewel = 0;
                    }
            }
    }
    return p;
}