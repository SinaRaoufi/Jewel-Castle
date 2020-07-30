#include "Jewels/BlueJewel.hpp"

BlueJewel::BlueJewel() : Jewel(BLUE_JEWEL_SCORE)
{
    // set blue jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setFillColor(sf::Color::Blue);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Cyan);
}