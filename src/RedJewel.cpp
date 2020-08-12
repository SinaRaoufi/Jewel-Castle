#include "Jewels/RedJewel.hpp"

using namespace std;

RedJewel::RedJewel() : Jewel(RED_JEWEL_SCORE)
{
    // set red jewel properties
    this->jewelTexture.loadFromFile(TEXTURE_DIRECTORY + string("red_jewel.png"));
    this->jewelSprite.setTexture(jewelTexture);
}