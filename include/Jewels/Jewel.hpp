#ifndef JEWEL_IG
#define JEWEL_IG

#include <SFML/Graphics.hpp>
#include "configs.hpp"

enum JewelsEnum
{
    YELLOW_JEWEL,
    GREEN_JEWEL,
    RED_JEWEL,
    BLUE_JEWEL,
    PINK_JEWEL,
    VIOLET_JEWEL
};

class Jewel
{
public:
    explicit Jewel(unsigned int);
    virtual ~Jewel() = 0;
    unsigned int getJewelScore() const;
    void render(sf::RenderWindow &);
    void setJewelPosition(float, float);
    bool isJewelSelected(sf::Vector2f);

protected:
    sf::CircleShape jewelShape;
    unsigned int score;
};

#endif