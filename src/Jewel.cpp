#include "Jewels/Jewel.hpp"

Jewel::Jewel(unsigned int score)
{
    if (score >= 10 && score <= 15)
        this->score = score;
}

void Jewel::render(sf::RenderWindow &window)
{
    window.draw(this->jewelShape);
}

unsigned int Jewel::getJewelScore() const
{
    return this->score;
}

void Jewel::setJewelPosition(float x, float y)
{
    this->jewelShape.setPosition(x, y);
}

bool Jewel::isJewelSelected(sf::Vector2f mousePoint)
{
    if (this->jewelShape.getGlobalBounds().contains(mousePoint))
        return true;
    return false;
}