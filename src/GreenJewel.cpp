#include "Jewels/GreenJewel.hpp"

GreenJewel::GreenJewel() : Jewel(GREEN_JEWEL_SCORE)
{
    // set green jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setFillColor(sf::Color::Green);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Cyan);
}