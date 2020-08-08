#include "Timer.hpp"
#include "configs.hpp"
#include <string>

using namespace std;

Timer::Timer(int countDown): countDown(sf::seconds(countDown))
{
    this->timerTexture.loadFromFile(PROGRESS_BAR_TEXTURE_DIRECTORY + string("timer_progress_bar.png"));
    this->timerTexture.setSmooth(true);
    this->timerSprite.setTexture(timerTexture);
    this->timerFont.loadFromFile(FONT_DIRECTORY + string("Xerox Sans Serif Narrow Bold.ttf"));
    this->timerText.setFont(timerFont);
    this->timerText.setCharacterSize(20);
    this->timerText.setOutlineThickness(1);
    this->timerText.setOutlineColor(sf::Color::Yellow);
    this->timerText.setFillColor(sf::Color::Blue);
}

void Timer::updateTime()
{
    if (clock.getElapsedTime().asSeconds() >= 1)
    {
        this->countDown -= sf::seconds(1);
        this->clock.restart();
    }
}

void Timer::setTimerProgressBarPosition(float x, float y)
{
    this->timerSprite.setPosition(sf::Vector2f(x, y));
    this->timerText.setPosition(x + 7, y + 25);
}

void Timer::render(sf::RenderWindow &window)
{
    string temp = to_string(static_cast<unsigned short int>(this->countDown.asSeconds()));
    this->timerText.setString(temp);
    window.draw(this->timerSprite);
    window.draw(this->timerText);
}