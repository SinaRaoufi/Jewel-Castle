#include "Jewels/BlueJewel.hpp"

using namespace std;

BlueJewel::BlueJewel() : Jewel(BLUE_JEWEL_SCORE)
{
    // set blue jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setPointCount(5);
    this->jewelShape.setFillColor(sf::Color::Blue);
    this->jewelShape.setOutlineThickness(1);
    this->jewelShape.setOutlineColor(sf::Color::Blue);
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("blueT.png"));
    this->jewelTexture.setSmooth(true);
    this->jewelShape.setTexture(&jewelTexture);
}