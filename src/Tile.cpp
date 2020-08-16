#include "Tile.hpp"
#include "configs.hpp"
#include <string>

using namespace std;

Tile::Tile()
{
    // tile shape properties
    this->tileTexture.loadFromFile(TILE_TEXTURE_DIRECTORY + string("tile_background.jpg"));
    this->tileSprite.setTexture(this->tileTexture);

    this->selectedTileTexture.loadFromFile(TILE_TEXTURE_DIRECTORY + string("tile_background_selected.jpg"));
}

void Tile::setTilePosition(float x, float y)
{
    this->tileSprite.setPosition(x * TILE_WIDTH + 150, TILE_HEIGHT * y + 150);
}

void Tile::render(sf::RenderWindow &window)
{
    window.draw(this->tileSprite);
}

bool Tile::isTileSelected(sf::Vector2f mousePoint)
{
    if (this->tileSprite.getGlobalBounds().contains(mousePoint))
        return true;
    return false;
}

void Tile::enableTileOutline()
{
    this->tileSprite.setTexture(this->selectedTileTexture);
}

void Tile::disableTileOutline()
{
    this->tileSprite.setTexture(this->tileTexture);
}