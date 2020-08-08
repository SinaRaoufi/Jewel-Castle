#include "Button.hpp"

using namespace std;

Button::Button(string texturePath)
{
    this->buttonTexture.loadFromFile(texturePath);
    this->buttonSprite.setTexture(this->buttonTexture);
}

// set button position
void Button::setButtonPosition(float x, float y)
{
    this->buttonSprite.setPosition(sf::Vector2f(x, y));
}

// display button
void Button::render(sf::RenderWindow &window)
{
    window.draw(this->buttonSprite);
}

// check if button pressed or not
bool Button::isButtonPressed(sf::Vector2f mousePoint)
{
    if (buttonSprite.getGlobalBounds().contains(mousePoint))
        return true;
    return false;
}