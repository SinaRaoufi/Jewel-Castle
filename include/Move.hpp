#ifndef MOVE_IG
#define MOVE_IG

#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Move
{
public:
    explicit Move(unsigned int);
    bool isMoveValid(const Board &, size_t, size_t, size_t, size_t) const;
    unsigned int getNumberOfMove() const;
    void decreaseNumberOfMoveByOne();
    void setMoveProgressBarPosition(float, float);
    void render(sf::RenderWindow &);

private:
    unsigned int numberOfMove;
    sf::Sprite moveSprite;
    sf::Texture moveTexture;
    sf::Font moveFont;
    sf::Text moveText;
    bool checkVerticalMove(const Board &, int, int, int, int) const;
    bool checkHorizontalMove(const Board &, int, int, int, int) const;
};

#endif