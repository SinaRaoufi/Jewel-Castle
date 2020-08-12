#include "Jewels/BlueJewel.hpp"

using namespace std;

BlueJewel::BlueJewel() : Jewel(BLUE_JEWEL_SCORE)
{
    // set blue jewel properties
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("blue_jewel.png"));
    this->jewelSprite.setTexture(jewelTexture);
}