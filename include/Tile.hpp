#ifndef Tile_IG
#define Tile_IG

#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile(float, float, sf::Color, sf::Color);
    void setTilePosition(float, float);
    void render(sf::RenderWindow &);

private:
    sf::RectangleShape tileShape;
};

#endif