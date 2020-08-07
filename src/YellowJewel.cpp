#include "Jewels/YellowJewel.hpp"

using namespace std;

YellowJewel::YellowJewel() : Jewel(YELLOW_JEWEL_SCORE)
{
    // set yellow jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setPointCount(6);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Yellow);
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("yellowT.png"));
    this->jewelTexture.setSmooth(true);
    this->jewelShape.setTexture(&jewelTexture);
}