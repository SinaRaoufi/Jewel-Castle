#ifndef JEWEL_IG
#define JEWEL_IG

#include <SFML/Graphics.hpp>
#include "configs.hpp"

class Jewel
{
public:
    explicit Jewel(unsigned int);
    // ~Jewel();
    unsigned int getJewelScore() const;
    void render(sf::RenderWindow &);
    void setJewelPosition(float, float);
    bool isJewelSelected(sf::Vector2f);

protected:
    sf::CircleShape jewelShape;
    unsigned int score;
};

#endif