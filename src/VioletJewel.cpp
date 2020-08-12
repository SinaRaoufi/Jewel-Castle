#include "Jewels/VioletJewel.hpp"

using namespace std;

VioletJewel::VioletJewel() : Jewel(VIOLET_JEWEL_SCORE)
{
    // set violet jewel properties
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("violet_jewel.png"));
    this->jewelSprite.setTexture(jewelTexture);
}