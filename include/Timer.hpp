#ifndef TIMER_IG
#define TIMER_IG

#include <SFML/Graphics.hpp>

class Timer
{
public:
    explicit Timer(int);
    void updateTime();
    void setTimerProgressBarPosition(float, float);
    void render(sf::RenderWindow &);

private:
    sf::Time countDown;
    sf::Clock clock;
    sf::Sprite timerSprite;
    sf::Texture timerTexture;
    sf::Font timerFont;
    sf::Text timerText;
};

#endif