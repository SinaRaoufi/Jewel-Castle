#include "Tile.hpp"
#include "configs.hpp"

Tile::Tile(float width, float height, sf::Color tileColor, sf::Color tileOutlineColor): tileColor(tileColor)
{
    // tile shape properties
    this->tileShape.setSize(sf::Vector2f(width, height));
    this->tileShape.setFillColor(tileColor);
    this->tileShape.setOutlineColor(tileOutlineColor);
    this->tileShape.setOutlineThickness(2);
}

void Tile::setTilePosition(float x, float y)
{
    this->tileShape.setPosition(x * TILE_WIDTH + 150, TILE_HEIGHT * y + 150);
}

void Tile::render(sf::RenderWindow &window)
{
    window.draw(this->tileShape);
}

bool Tile::isTileSelected(sf::Vector2f mousePoint)
{
    if (tileShape.getGlobalBounds().contains(mousePoint))
        return true;
    return false;
}

void Tile::setTileColor(sf::Color color)
{
    this->tileShape.setFillColor(color);
}

void Tile::resetTileColorToDefualt()
{
    this->tileShape.setFillColor(tileColor);
}