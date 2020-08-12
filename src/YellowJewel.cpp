#include "Jewels/YellowJewel.hpp"

using namespace std;

YellowJewel::YellowJewel() : Jewel(YELLOW_JEWEL_SCORE)
{
    // set yellow jewel properties
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("yellow_jewel.png"));
    this->jewelSprite.setTexture(jewelTexture);
}