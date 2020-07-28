#ifndef BUTTON_IG
#define BUTTON_IG

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
    // Button();
    Button(float, float, float, float, std::string, std::string);
    void render(sf::RenderWindow &);
    bool isButtonPressed(sf::Vector2f);

private:
    sf::RectangleShape buttonShape;
    // sf::Texture buttonTexture;
    sf::Font buttonTextFont;
    sf::Text buttonText;
};

#endif