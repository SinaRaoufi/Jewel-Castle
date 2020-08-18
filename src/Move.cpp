#include "Move.hpp"

using namespace std;

Move::Move(unsigned int numOfMove) : numberOfMove(numOfMove)
{
    this->moveTexture.loadFromFile(PROGRESS_BAR_TEXTURE_DIRECTORY + string("move_progress_bar.png"));
    this->moveSprite.setTexture(this->moveTexture);
    this->moveFont.loadFromFile(FONT_DIRECTORY + string("Xerox Sans Serif Narrow Bold.ttf"));
    this->moveText.setFont(this->moveFont);
    this->moveText.setCharacterSize(30);
    this->moveText.setOutlineThickness(1.5);
    this->moveText.setOutlineColor(sf::Color::Blue);
    this->moveText.setFillColor(sf::Color::White);
}

// Check vertical move
bool Move::checkVerticalMove(const Board &gameBoard, int i1, int j1, int i2, int j2) const
{
    size_t numOfRow = gameBoard.getNumberOfRow();
    size_t numOfColumn = gameBoard.getNumberOfColumn();
    if (j2 - 1 >= 0 && j2 + 1 < numOfRow)
        if (*gameBoard.getListOfJewels()[i2][j2 - 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 + 1] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 - 1 >= 0 && j1 + 1 < numOfRow)
        if (*gameBoard.getListOfJewels()[i1][j1 - 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 + 1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j2 + 2 < numOfColumn)
        if (*gameBoard.getListOfJewels()[i2][j2 + 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 + 2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 + 2 < numOfColumn)
        if (*gameBoard.getListOfJewels()[i1][j1 + 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 + 2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j2 - 2 >= 0)
        if (*gameBoard.getListOfJewels()[i2][j2 - 1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2][j2 - 2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 - 2 >= 0)
        if (*gameBoard.getListOfJewels()[i1][j1 - 1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1][j1 - 2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (i1 - 3 >= 0 && i1 > i2)
        if (*gameBoard.getListOfJewels()[i1 - 2][j1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i1 - 3][j1] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i2 - 3 >= 0 && i2 > i1)
        if (*gameBoard.getListOfJewels()[i2 - 2][j2] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i2 - 3][j2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (i1 + 3 < numOfRow && i1 < i2)
        if (*gameBoard.getListOfJewels()[i1 + 2][j1] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i1 + 3][j1] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i2 + 3 < numOfRow && i2 < i1)
        if (*gameBoard.getListOfJewels()[i2 + 2][j2] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i2 + 3][j2] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    return false;
}

// Check horizantal move
bool Move::checkHorizontalMove(const Board &gameBoard, int i1, int j1, int i2, int j2) const
{
    size_t numOfRow = gameBoard.getNumberOfRow();
    size_t numOfColumn = gameBoard.getNumberOfColumn();
    if (i2 - 1 >= 0 && i2 + 1 < numOfRow)
        if (*gameBoard.getListOfJewels()[i2 - 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 + 1][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i1 - 1 >= 0 && i1 + 1 < numOfRow)
        if (*gameBoard.getListOfJewels()[i1 - 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 + 1][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (i2 + 2 < numOfRow)
        if (*gameBoard.getListOfJewels()[i2 + 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 + 2][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i1 + 2 < numOfRow)
        if (*gameBoard.getListOfJewels()[i1 + 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 + 2][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (i2 > 1)
        if (*gameBoard.getListOfJewels()[i2 - 1][j2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i2 - 2][j2] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (i1 > 1)
        if (*gameBoard.getListOfJewels()[i1 - 1][j1] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i1 - 2][j1] == *gameBoard.getListOfJewels()[i2][j2])
            return true;
    if (j2 + 3 < numOfColumn && j2 < j1)
        if ((*gameBoard.getListOfJewels()[i2][j2 + 2] == *gameBoard.getListOfJewels()[i2][j2] &&
             *gameBoard.getListOfJewels()[i2][j2 + 3] == *gameBoard.getListOfJewels()[i2][j2]))
            return true;
    if (j1 + 3 < numOfColumn && j1 < j2)
        if (*gameBoard.getListOfJewels()[i1][j1 + 2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i1][j1 + 3] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 > 2 && j2 < j1)
        if (*gameBoard.getListOfJewels()[i1][j1 - 2] == *gameBoard.getListOfJewels()[i1][j1] &&
            *gameBoard.getListOfJewels()[i1][j1 - 3] == *gameBoard.getListOfJewels()[i1][j1])
            return true;
    if (j1 > 1 && j2 > j1)
        if (*gameBoard.getListOfJewels()[i2][j2 - 2] == *gameBoard.getListOfJewels()[i2][j2] &&
            *gameBoard.getListOfJewels()[i2][j2 - 3] == *gameBoard.getListOfJewels()[i2][j2])
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

unsigned int Move::getNumberOfMove() const
{
    return this->numberOfMove;
}

void Move::decreaseNumberOfMoveByOne()
{
    this->numberOfMove--;
}

// Set position of move progress bar (contain number of move)
void Move::setMoveProgressBarPosition(float x, float y)
{
    this->moveSprite.setPosition(sf::Vector2f(x, y));
    this->moveText.setPosition(x + 19, y + 12);
}

// Show number of move
void Move::render(sf::RenderWindow &window)
{
    this->moveText.setString(to_string(this->numberOfMove));
    window.draw(this->moveSprite);
    window.draw(this->moveText);
}