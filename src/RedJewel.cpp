#include "Jewels/RedJewel.hpp"

using namespace std;

RedJewel::RedJewel() : Jewel(RED_JEWEL_SCORE)
{
    // set red jewel properties
    this->jewelShape.setRadius(20.f);
    this->jewelShape.setPointCount(7);
    this->jewelShape.setOutlineThickness(0.5);
    this->jewelShape.setOutlineColor(sf::Color::Red);
    this->jewelTexture.loadFromFile(Texture_DIRECTORY + string("redT.jpg"));
    this->jewelShape.setTexture(&jewelTexture);
}