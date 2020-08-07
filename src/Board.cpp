#include <Board.hpp>
#include <vector>
#include "RandomNumberGenerator.hpp"
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
            listOfTiles[i][j] = new Tile(TILE_WIDTH, TILE_HEIGHT, tileColor, sf::Color::Black);
            listOfTiles[i][j]->setTilePosition(j, i);
            listOfJewels[i][j]->setJewelPosition(j, i);
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
            if (*listOfJewels[i][j] == *listOfJewels[i][j + 1])
            {
                if (j + 2 == numberOfColumn)
                    continue;
                if (*listOfJewels[i][j + 1] == *listOfJewels[i][j + 2])
                    return false;
            }
    // Check jewels verticaly
    for (size_t j = 0; j < numberOfColumn; j++)
        for (size_t i = 0; i < numberOfRow - 1; i++)
            if (*listOfJewels[i][j] == *listOfJewels[i + 1][j])
            {
                if (i + 2 == numberOfRow)
                    continue;
                if (*listOfJewels[i + 1][j] == *listOfJewels[i + 2][j])
                    return false;
            }
    return true;
}

void Board::validateJewels()
{
    // Validate jewels horizontaly
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn - 1; j++)
            if (*listOfJewels[i][j] == *listOfJewels[i][j + 1])
            {
                if (j + 2 == numberOfColumn)
                    continue;
                if (*listOfJewels[i][j + 1] == *listOfJewels[i][j + 2])
                {
                    delete listOfJewels[i][j + 1];
                    listOfJewels[i][j + 1] = generateRandomJewel();
                }
            }
    // Validate jewels verticaly
    for (size_t j = 0; j < numberOfColumn; j++)
        for (size_t i = 0; i < numberOfRow - 1; i++)
            if (*listOfJewels[i][j] == *listOfJewels[i + 1][j])
            {
                if (i + 2 == numberOfRow)
                    continue;
                if (*listOfJewels[i + 1][j] == *listOfJewels[i + 2][j])
                {
                    delete listOfJewels[i + 1][j];
                    listOfJewels[i + 1][j] = generateRandomJewel();
                }
            }
}

void Board::swapTwoJewels(size_t i1, size_t j1, size_t i2, size_t j2)
{
    listOfJewels[i1][j1]->setJewelPosition(j2, i2);
    listOfJewels[i2][j2]->setJewelPosition(j1, i1);
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
                    if (*listOfJewels[i][j] == *listOfJewels[i][j + 1] &&
                        *listOfJewels[i][j + 1] == *listOfJewels[i][j + 2])
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
                                    listOfJewels[f + 1][k]->setJewelPosition(k, (f + 1));
                                }
                            listOfJewels[0][k] = generateRandomJewel();
                            while (listOfJewels[0][k]->getJewelScore() == jewelScore)
                            {
                                delete listOfJewels[0][k];
                                listOfJewels[0][k] = generateRandomJewel();
                            }
                            listOfJewels[0][k]->setJewelPosition(k, 0);
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
                    if (*listOfJewels[i][j] == *listOfJewels[i - 1][j] &&
                        *listOfJewels[i - 1][j] == *listOfJewels[i - 2][j])
                    {
                        us jewelScore = listOfJewels[i][j]->getJewelScore();
                        while (listOfJewels[i][j]->getJewelScore() == jewelScore)
                        {
                            delete listOfJewels[i][j];
                            for (int f = i - 1; f != -1; f--) // could be a single function (Use DRY principle)
                            {
                                listOfJewels[f + 1][j] = listOfJewels[f][j];
                                listOfJewels[f + 1][j]->setJewelPosition(j, (f + 1));
                            }
                            listOfJewels[0][j] = generateRandomJewel();
                            while (listOfJewels[0][j]->getJewelScore() == jewelScore)
                            {
                                delete listOfJewels[0][j];
                                listOfJewels[0][j] = generateRandomJewel();
                            }
                            listOfJewels[0][j]->setJewelPosition(j, 0);
                            numberOfDeletedJewel++;
                        }
                        p.push_back(make_pair(numberOfDeletedJewel, jewelScore));
                        numberOfDeletedJewel = 0;
                    }
            }
    }
    return p;
}

void Board::removeRow(size_t i)
{
    for (size_t j = 0; j < numberOfColumn; j++)
    {
        delete listOfJewels[i][j];
        if (i != 0)
            for (int f = i - 1; f != -1; f--) // could be a single function (Use DRY principle)
            {
                listOfJewels[f + 1][j] = listOfJewels[f][j];
                listOfJewels[f + 1][j]->setJewelPosition(j, (f + 1));
            }
        listOfJewels[0][j] = generateRandomJewel();
        listOfJewels[0][j]->setJewelPosition(j, 0);
    }
    while (!isJewelsCombinationValid())
        refreshBoard();
}

void Board::removeRectangle(size_t i, size_t j)
{
    if (i - 4 < 0)
        i = 0;
    else if (i + 4 > numberOfRow)
        i = 5;
    if (j - 4 < 0)
        j = 0;
    else if (j + 4 > numberOfColumn)
        j = 5;
    for (size_t k = i; k < i + 4; k++)
        for (size_t f = j; f < j + 4; f++)
        {
            cout << k << ' ' << f << endl;
            delete listOfJewels[k][f];
            listOfJewels[k][f] = generateRandomJewel();
            listOfJewels[k][f]->setJewelPosition(f, k);
        }
}

void Board::removeThreeRowColumn(size_t i, size_t j)
{
    if (i - 4 < 0)
        i = 0;
    else if (i + 4 > numberOfRow)
        i = 5;
    if (j - 4 < 0)
        j = 0;
    else if (j + 4 > numberOfColumn)
        j = 5;
    for (size_t k = i; k < i + 4; k++)
        for (size_t f = j; f < j + 4; f++)
        {
            cout << k << ' ' << f << endl;
            delete listOfJewels[k][f];
            listOfJewels[k][f] = generateRandomJewel();
            listOfJewels[k][f]->setJewelPosition(f, k);
        }
}