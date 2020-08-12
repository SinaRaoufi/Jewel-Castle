#ifndef MOVE_IG
#define MOVE_IG

#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Move
{
public:
    bool isMoveValid(const Board &, size_t, size_t, size_t, size_t) const;
    // void render(sf::RenderWindow &);

private:
    // sf::Sprite moveSprite;
    // sf::Texture moveTexture;
    // sf::Font moveFont;
    // sf::Text moveText;
    bool checkVerticalMove(const Board &, size_t, size_t, size_t, size_t) const;
    bool checkHorizontalMove(const Board &, size_t, size_t, size_t, size_t) const;
};

#endif