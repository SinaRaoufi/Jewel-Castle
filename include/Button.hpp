#ifndef BUTTON_IG
#define BUTTON_IG

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
    // Button();
    Button(std::string, std::string);
    Button(size_t, std::string, std::string);
    void setButtonPosition(float, float);
    void setButtonTexture(std::string);
    bool isButtonPressed(sf::Vector2f);
    void render(sf::RenderWindow &);

private:
    sf::CircleShape buttonShape;
    sf::Texture buttonTexture;
    sf::Font buttonTextFont;
    sf::Text buttonText;
};

#endif