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

void Board::render(sf::RenderWindow &window)
{
    for (auto row : listOfTiles)
        for (auto item : row)
            item->render(window);
}
