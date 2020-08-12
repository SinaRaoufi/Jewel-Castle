#include "Jewels/PinkJewel.hpp"

using namespace std;

PinkJewel::PinkJewel() : Jewel(PINK_JEWEL_SCORE)
{
    // set pink jewel properties
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("pink_jewel.png"));
    this->jewelSprite.setTexture(jewelTexture);
}