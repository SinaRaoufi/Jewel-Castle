#include "Move.hpp"

#include <iostream>

using namespace std;

bool isMoveValid(const Board &gameBoard, size_t i1, size_t j1, size_t i2, size_t j2) // need optimization
{
    // Check vertical move
    if (j1 == j2)
    {
        if (j2 != 0 || j2 != NUM_OF_COLUMN - 1)
            if (gameBoard.getListOfJewels()[i2][j2 - 1]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2][j2 + 1]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (j2 != NUM_OF_COLUMN - 1)
            if (gameBoard.getListOfJewels()[i2][j2 + 1]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2][j2 + 2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (j2 != 0)
            if (gameBoard.getListOfJewels()[i2][j2 - 1]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2][j2 - 2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (j1 != 0 || j1 != NUM_OF_COLUMN - 1)
            if (gameBoard.getListOfJewels()[i1][j1 - 1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1][j1 + 1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        if (j1 != NUM_OF_COLUMN - 1)
            if (gameBoard.getListOfJewels()[i1][j1 + 1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1][j1 + 2]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        if (j1 != 0)
            if (gameBoard.getListOfJewels()[i1][j1 - 1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1][j1 - 2]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        if (i2 != 0)
            if (gameBoard.getListOfJewels()[i2 - 1][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2 - 2][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (i1 != 0)
            if (gameBoard.getListOfJewels()[i1 - 1][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1 - 2][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        if (i2 != NUM_OF_ROW)
            if (gameBoard.getListOfJewels()[i2 + 1][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2 + 2][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (i1 != NUM_OF_ROW)
            if (gameBoard.getListOfJewels()[i1 + 1][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1 + 2][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
    }
    // Check horizantal move
    if (i1 == i2)
    {
        if (i2 != 0)
        {
            if (gameBoard.getListOfJewels()[i2 - 1][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2 + 1][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
            if (gameBoard.getListOfJewels()[i2 - 1][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2 - 2][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        }
        if (i1 != 0)
        {
            if (gameBoard.getListOfJewels()[i1 - 1][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1 + 1][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
            if (gameBoard.getListOfJewels()[i1 - 1][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1 - 2][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        }
        if (i2 != NUM_OF_ROW - 1)
            if (gameBoard.getListOfJewels()[i2 + 1][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2 + 2][j2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (i1 != NUM_OF_ROW - 1)
            if (gameBoard.getListOfJewels()[i1 + 1][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1 + 2][j1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        if (j2 != NUM_OF_COLUMN - 1)
            if (gameBoard.getListOfJewels()[i2][j2 + 1]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2][j2 + 2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (j1 != NUM_OF_COLUMN - 1)
            if (gameBoard.getListOfJewels()[i1][j1 + 1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1][j1 + 2]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
        if (j2 != 0)
            if (gameBoard.getListOfJewels()[i2][j2 - 1]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore() &&
                gameBoard.getListOfJewels()[i2][j2 - 2]->getJewelScore() == gameBoard.getListOfJewels()[i1][j1]->getJewelScore())
                return true;
        if (j1 != 0)
            if (gameBoard.getListOfJewels()[i1][j1 - 1]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore() &&
                gameBoard.getListOfJewels()[i1][j1 - 2]->getJewelScore() == gameBoard.getListOfJewels()[i2][j2]->getJewelScore())
                return true;
    }
    return false;
}