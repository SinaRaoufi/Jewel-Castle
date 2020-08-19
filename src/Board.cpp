#include <Board.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "RandomNumberGenerator.hpp"

#include "Jewels/YellowJewel.hpp"
#include "Jewels/GreenJewel.hpp"
#include "Jewels/RedJewel.hpp"
#include "Jewels/BlueJewel.hpp"
#include "Jewels/PinkJewel.hpp"
#include "Jewels/VioletJewel.hpp"

using namespace std;

Board::Board()
{
    // initializes each element of listOfJewels to nullptr
    for (auto &row : listOfJewels)
        for (auto &jewel : row)
            jewel = nullptr;
    // initializes each element of listOfTiles to nullptr
    for (auto &row : listOfTiles)
        for (auto &tile : row)
            tile = nullptr;
    // generate random jewels for each tile
    shuffleJewels(listOfJewels);
    // validates jewels combination
    while (!isJewelsCombinationValid())
        validateJewels();
    // sets tiles and jewels position
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
        {
            listOfTiles[i][j] = new Tile();
            listOfTiles[i][j]->setTilePosition(j, i);
            listOfJewels[i][j]->setJewelPosition(j, i);
        }
}

Board::~Board()
{
    // deletes each tile that allocated dynamically
    for (auto &row : listOfTiles)
        for (auto &tile : row)
            delete tile;

    //deletes each jewel that allocated dynamically
    for (auto &row : listOfJewels)
        for (auto &jewel : row)
            delete jewel;
}

void Board::render(sf::RenderWindow &window)
{
    // draws each tile in the window
    for (auto row : listOfTiles)
        for (auto tile : row)
            tile->render(window);
    // draws each jewel in the window
    for (auto row : listOfJewels)
        for (auto jewel : row)
            jewel->render(window);
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

// generate one jewel and return it
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

void Board::shuffleJewels(JewelList &listOfJewels)
{
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
        {
            if (listOfJewels[i][j] != nullptr)
                delete listOfJewels[i][j];
            listOfJewels[i][j] = generateRandomJewel();
        }
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

// if three or more jewels are next to each other, it fixes their combination
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

void Board::swapTwoJewels(size_t i1, size_t j1, size_t i2, size_t j2, sf::RenderWindow &window)
{

    sf::Time time = sf::microseconds(2);
    sf::Clock clock;
    size_t i = 0;
    while (i < 2)
    {
        while (clock.getElapsedTime().asMicroseconds() < time.asMicroseconds())
        {
            if (clock.getElapsedTime().asMicroseconds() >= time.asMicroseconds())
            {
                if (i1 == i2)
                {
                    if (j1 > j2)
                    {
                        listOfJewels[i1][j1]->moveJewel(-22.5, 0);
                        listOfJewels[i2][j2]->moveJewel(22.5, 0);
                    }
                    else
                    {
                        listOfJewels[i1][j1]->moveJewel(22.5, 0);
                        listOfJewels[i2][j2]->moveJewel(-22.5, 0);
                    }
                }
                else
                {
                    if (i1 < i2)
                    {
                        listOfJewels[i1][j1]->moveJewel(0, 22.5);
                        listOfJewels[i2][j2]->moveJewel(0, -22.5);
                    }
                    else
                    {
                        listOfJewels[i1][j1]->moveJewel(0, -22.5);
                        listOfJewels[i2][j2]->moveJewel(0, 22.5);
                    }
                }

                listOfJewels[i1][j1]->render(window);
                listOfJewels[i2][j2]->render(window);
                window.display();
                i++;
            }
        }
        clock.restart();
    }
    swap(listOfJewels[i1][j1], listOfJewels[i2][j2]);
}

scorePair Board::refreshBoard()
{
    us numberOfDeletedJewel = 0;
    scorePair result;
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
                                for (int f = i - 1; f != -1; f--)
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
                        result.push_back(make_pair(numberOfDeletedJewel, jewelScore));
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
                        result.push_back(make_pair(numberOfDeletedJewel, jewelScore));
                        numberOfDeletedJewel = 0;
                    }
            }
    }
    return result;
}

unsigned int Board::removeRow(size_t rowIndex)
{
    scorePair result;
    unsigned int score = 0;
    for (size_t j = 0; j < numberOfColumn; j++)
    {
        score += listOfJewels[rowIndex][j]->getJewelScore();
        delete listOfJewels[rowIndex][j];
        if (rowIndex != 0)
            for (int f = rowIndex - 1; f != -1; f--) 
            {
                listOfJewels[f + 1][j] = listOfJewels[f][j];
                listOfJewels[f + 1][j]->setJewelPosition(j, (f + 1));
            }
        listOfJewels[0][j] = generateRandomJewel();
        listOfJewels[0][j]->setJewelPosition(j, 0);
    }
    while (!isJewelsCombinationValid())
    {
        result = refreshBoard();
        for (const auto &item : result)
            score += item.second;
    }
    return score;
}

unsigned int Board::removeRectangle(size_t rowIndex, size_t columnIndex)
{
    scorePair result;
    unsigned int score = 0;
    if (rowIndex + 4 > numberOfRow)
        rowIndex = 5;
    if (columnIndex + 4 > numberOfColumn)
        columnIndex = 5;
    for (size_t i = rowIndex; i < rowIndex + 4; i++)
        for (size_t j = columnIndex; j < columnIndex + 4; j++)
        {
            score += listOfJewels[i][j]->getJewelScore();
            delete listOfJewels[i][j];
            listOfJewels[i][j] = generateRandomJewel();
            listOfJewels[i][j]->setJewelPosition(j, i);
        }
    while (!isJewelsCombinationValid())
    {
        result = refreshBoard();
        for (const auto &item : result)
            score += item.second;
    }
    return score;
}

unsigned int Board::removeThreeRowColumn(size_t rowIndex, size_t columnIndex)
{
    unsigned int score = 0;
    scorePair result;
    if (rowIndex > 6)
        rowIndex = 6;
    if (columnIndex > 6)
        columnIndex = 6;
    for (size_t j = columnIndex; j < columnIndex + 3; j++)
        for (size_t i = 0; i < numberOfRow; i++)
        {
            score += listOfJewels[i][j]->getJewelScore();
            delete listOfJewels[i][j];
            listOfJewels[i][j] = generateRandomJewel();
            listOfJewels[i][j]->setJewelPosition(j, i);
        }
    for (size_t i = rowIndex; i < rowIndex + 3; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
        {
            if (j == columnIndex)
            {
                j = columnIndex + 2;
                continue;
            }
            score += listOfJewels[i][j]->getJewelScore();
            delete listOfJewels[i][j];
            listOfJewels[i][j] = generateRandomJewel();
            listOfJewels[i][j]->setJewelPosition(j, i);
        }
    while (!isJewelsCombinationValid())
    {
        result = refreshBoard();
        for (const auto &item : result)
            score += item.second;
    }
    return score;
}