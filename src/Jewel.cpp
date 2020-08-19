#include "Jewels/Jewel.hpp"

Jewel::Jewel(unsigned int score)
{
    // set jewel's score
    if (score >= 10 && score <= 15)
        this->score = score;
}

// draw jewel on the window
void Jewel::render(sf::RenderWindow &window)
{
    window.draw(this->jewelSprite);
}

// return jewel's score
unsigned int Jewel::getJewelScore() const
{
    return this->score;
}

// set the position of jewel
void Jewel::setJewelPosition(float x, float y)
{
    this->jewelSprite.setPosition(x * TILE_WIDTH + 150, TILE_HEIGHT * y + 150);
}

// changes the position of the jewel according to the current position of jewel
void Jewel::moveJewel(float x, float y)
{
    this->jewelSprite.move(sf::Vector2f(x, y));
}

// overloading operator == for check equality of two jewels
bool Jewel::operator==(const Jewel &secondJewel)
{
    return this->score == secondJewel.score;
}

Jewel::~Jewel(){};