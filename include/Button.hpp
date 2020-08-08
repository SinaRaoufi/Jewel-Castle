#ifndef BUTTON_IG
#define BUTTON_IG

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
    Button(std::string);
    void setButtonPosition(float, float);
    bool isButtonPressed(sf::Vector2f);
    void render(sf::RenderWindow &);

private:
    sf::Sprite buttonSprite;
    sf::Texture buttonTexture;
};

#endif