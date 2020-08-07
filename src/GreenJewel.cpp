#include "Jewels/GreenJewel.hpp"

using namespace std;

GreenJewel::GreenJewel() : Jewel(GREEN_JEWEL_SCORE)
{
    // set green jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setPointCount(4);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Green);
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("greenT.jpg"));
    this->jewelShape.setTexture(&jewelTexture);
}