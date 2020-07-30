#include <Board.hpp>
#include <SFML/Graphics.hpp>

Board::Board()
{
    for (size_t i = 0; i < numberOfRow; i++)
        for (size_t j = 0; j < numberOfColumn; j++)
        {
            listOfTiles[i][j] = new Tile(Tile_WIDTH, Tile_HEIGHT, sf::Color::Blue, sf::Color::Black);
            listOfTiles[i][j]->setTilePosition(j * Tile_WIDTH + 150, Tile_HEIGHT * i + 150);
        }
}

Board::~Board()
{
    for (auto &row : listOfTiles)
        for (auto &item : row)
            delete item;
}

void Board::render(sf::RenderWindow &window)
{
    for (auto row : listOfTiles)
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