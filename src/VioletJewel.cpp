#include "Jewels/VioletJewel.hpp"

VioletJewel::VioletJewel() : Jewel(VIOLET_JEWEL_SCORE)
{
    // set violet jewel properties
    this->jewelShape.setRadius(20.f);
    sf::Color violetColor(148, 0, 211);
    this->jewelShape.setFillColor(violetColor);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Cyan);
}