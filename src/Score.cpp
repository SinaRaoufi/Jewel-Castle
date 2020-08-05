#include "Score.hpp"
#include "configs.hpp"
#include <string>

using namespace std;

Score::Score(us requiredScore, us currentScore) : requiredScore(requiredScore), currentScore(currentScore)
{
    this->scoreTextFont.loadFromFile(FONT_DIRECTORY + string("Xerox Sans Serif Narrow Bold.ttf"));
    this->scoreText.setFont(scoreTextFont);
    this->scoreText.setCharacterSize(26);
    this->scoreText.setOutlineThickness(1.5);
    this->scoreText.setOutlineColor(sf::Color::White);
    this->scoreText.setFillColor(sf::Color::Blue);
    this->scoreText.setPosition(100, 100);
}

void Score::increaseScore(us score)
{
    this->currentScore += score;
}

void Score::decreaseScore(us score)
{
    this->currentScore -= score;
}

us Score::getCurrentScore() const
{
    return this->currentScore;
}

us Score::getRequiredScore() const
{
    return this->requiredScore;
}

void Score::render(sf::RenderWindow &window)
{
    string temp = to_string(currentScore) + "/" + to_string(requiredScore);
    this->scoreText.setString(temp);
    window.draw(this->scoreText);
}