#include "Jewels/YellowJewel.hpp"

YellowJewel::YellowJewel() : Jewel(YELLOW_JEWEL_SCORE)
{
    // set yellow jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setFillColor(sf::Color::Yellow);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Cyan);
}