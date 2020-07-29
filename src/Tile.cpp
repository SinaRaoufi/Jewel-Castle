#include "Tile.hpp"

Tile::Tile(float width, float height, sf::Color tileColor, sf::Color tileOutlineColor)
{
    // tile shape properties
    this->tileShape.setSize(sf::Vector2f(width, height));
    this->tileShape.setFillColor(tileColor);
    this->tileShape.setOutlineColor(tileOutlineColor);
    this->tileShape.setOutlineThickness(2);
}

void Tile::setTilePosition(float x, float y)
{
    this->tileShape.setPosition(x, y);
}

void Tile::render(sf::RenderWindow &window)
{
    window.draw(this->tileShape);
}
