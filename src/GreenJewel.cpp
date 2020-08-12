#include "Jewels/GreenJewel.hpp"

using namespace std;

GreenJewel::GreenJewel() : Jewel(GREEN_JEWEL_SCORE)
{
    // set green jewel properties
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("green_jewel.png"));
    this->jewelSprite.setTexture(jewelTexture);
}