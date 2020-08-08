#ifndef SCORE_IG
#define SCORE_IG

#include <SFML/Graphics.hpp>

typedef unsigned short int us;

class Score final
{

public:
    Score(us, us = 0);
    void increaseScore(us);
    void decreaseScore(us);
    us getCurrentScore() const;
    us getRequiredScore() const;
    void setScoreProgressBarPosition(float, float);
    void render(sf::RenderWindow&);

private:
    us currentScore;
    us requiredScore;
    sf::Sprite scoreSprite;
    sf::Texture scoreTexture;
    sf::Font scoreTextFont;
    sf::Text scoreText;
};

#endif