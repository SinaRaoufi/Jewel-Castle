#include "Button.hpp"

using namespace std;

// Button::Button(){};

Button::Button(float x, float y, float width, float height, string fontPath, string text)
{
    // button shape properties
    this->buttonShape.setPosition(sf::Vector2f(x, y));
    this->buttonShape.setSize(sf::Vector2f(width, height));
    this->buttonShape.setFillColor(sf::Color::Green);

    // button font properties
    this->buttonTextFont.loadFromFile(fontPath);

    // button text properties
    this->buttonText.setFont(buttonTextFont);
    this->buttonText.setString(text);
    this->buttonText.setCharacterSize(26);
    this->buttonText.setOutlineColor(sf::Color::White);
    this->buttonText.setFillColor(sf::Color::Black);
    this->buttonText.setPosition(buttonShape.getPosition().x * 0.5,
                                 buttonShape.getPosition().y * 0.5);
}

// display button
void Button::render(sf::RenderWindow &window)
{
    window.draw(this->buttonShape);
    window.draw(this->buttonText);
}

// check if button pressed or not
bool Button::isButtonPressed(sf::Vector2f mousePoint)
{
    if (buttonShape.getGlobalBounds().contains(mousePoint))
    {
        return true;
    }
    return false;
}