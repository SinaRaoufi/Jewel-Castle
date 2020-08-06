#include "Button.hpp"

using namespace std;

// Button::Button(){};

Button::Button(string fontPath, string text) : buttonShape(20.f)
{
    // button shape properties
    this->buttonShape.setFillColor(sf::Color::Green);
    // this->buttonShape.setRadius(20.f);

    // button font properties
    this->buttonTextFont.loadFromFile(fontPath);

    // button text properties
    this->buttonText.setFont(buttonTextFont);
    this->buttonText.setString(text);
    this->buttonText.setCharacterSize(26);
    this->buttonText.setOutlineColor(sf::Color::White);
    this->buttonText.setFillColor(sf::Color::Black);
}

Button::Button(size_t numberOfSites, string fontPath, string text) : Button(fontPath, text)
{
    this->buttonShape.setPointCount(numberOfSites);
}

// set button position
void Button::setButtonPosition(float x, float y)
{
    this->buttonShape.setPosition(sf::Vector2f(x, y));
}

// set button texture
void Button::setButtonTexture(string texturePath)
{
    this->buttonTexture.loadFromFile(texturePath);
    this->buttonShape.setTexture(&this->buttonTexture);
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
        return true;
    return false;
}