#include "Jewels/PinkJewel.hpp"

PinkJewel::PinkJewel() : Jewel(PINK_JEWEL_SCORE)
{
    // set pink jewel properties
    this->jewelShape.setRadius(20.f);
    sf::Color pinkColor(255, 20, 147);
    this->jewelShape.setFillColor(pinkColor);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Cyan);
}