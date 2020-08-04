#include "Jewels/PinkJewel.hpp"

using namespace std;

PinkJewel::PinkJewel() : Jewel(PINK_JEWEL_SCORE)
{
    // set pink jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setPointCount(5);
    sf::Color pinkColor(255, 20, 147);
    this->jewelShape.setFillColor(pinkColor);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Red);
    this->jewelTexture.loadFromFile(Texture_DIRECTORY + string("pinkT.jpg"));
    this->jewelShape.setTexture(&jewelTexture);
}