#include "Move.hpp"

// Check vertical move
bool Move::checkVerticalMove(const Board &gameBoard, size_t i1, size_t j1, size_t i2, size_t j2) const
{
    if (j2 != 0 || j2 != NUM_OF_COLUMN - 1)
        if (*gameBoard.getListOfJewels()[i2][j2 - 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 + 1] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j2 != NUM_OF_COLUMN - 1)
        if (*gameBoard.getListOfJewels()[i2][j2 + 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 + 2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j2 != 0)
        if (*gameBoard.getListOfJewels()[i2][j2 - 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 - 2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 != 0 || j1 != NUM_OF_COLUMN - 1)
        if (*gameBoard.getListOfJewels()[i1][j1 - 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 + 1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j1 != NUM_OF_COLUMN - 1)
        if (*gameBoard.getListOfJewels()[i1][j1 + 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 + 2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j1 != 0)
        if (*gameBoard.getListOfJewels()[i1][j1 - 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 - 2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (i2 != 0)
        if (*gameBoard.getListOfJewels()[i2 - 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 - 2][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i1 != 0)
        if (*gameBoard.getListOfJewels()[i1 - 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 - 2][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (i2 != NUM_OF_ROW)
        if (*gameBoard.getListOfJewels()[i2 + 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 + 2][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i1 != NUM_OF_ROW)
        if (*gameBoard.getListOfJewels()[i1 + 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 + 2][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    return false;
}

// Check horizantal move
bool Move::checkHorizontalMove(const Board &gameBoard, size_t i1, size_t j1, size_t i2, size_t j2) const
{
    if (i2 != 0)
    {
        if (*gameBoard.getListOfJewels()[i2 - 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 + 1][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
        if (*gameBoard.getListOfJewels()[i2 - 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 - 2][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    }
    if (i1 != 0)
    {
        if (*gameBoard.getListOfJewels()[i1 - 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 + 1][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
        if (*gameBoard.getListOfJewels()[i1 - 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 - 2][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    }
    if (i2 != NUM_OF_ROW - 1)
        if (*gameBoard.getListOfJewels()[i2 + 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 + 2][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i1 != NUM_OF_ROW - 1)
        if (*gameBoard.getListOfJewels()[i1 + 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 + 2][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j2 != NUM_OF_COLUMN - 1)
        if (*gameBoard.getListOfJewels()[i2][j2 + 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 + 2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 != NUM_OF_COLUMN - 1)
        if (*gameBoard.getListOfJewels()[i1][j1 + 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 + 2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j2 != 0)
        if (*gameBoard.getListOfJewels()[i2][j2 - 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 - 2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 != 0)
        if (*gameBoard.getListOfJewels()[i1][j1 - 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 - 2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    return false;
}

bool Move::isMoveValid(const Board &gameBoard, size_t i1, size_t j1, size_t i2, size_t j2) const
{
    // Check vertical move
    if (j1 == j2)
        return checkVerticalMove(gameBoard, i1, j1, i2, j2);
    // Check horizantal move
    if (i1 == i2)
        return checkHorizontalMove(gameBoard, i1, j1, i2, j2);
}