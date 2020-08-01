#include "Jewels/RedJewel.hpp"

RedJewel::RedJewel() : Jewel(RED_JEWEL_SCORE)
{
    // set red jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setPointCount(7);
    this->jewelShape.setFillColor(sf::Color::Red);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Cyan);
}