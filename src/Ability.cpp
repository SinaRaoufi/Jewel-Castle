#include "Abilities/Ability.hpp"

using namespace std;

Ability::Ability() : activation(false)
{
}

Ability::~Ability(){};

bool Ability::isAbilityActive() const
{
    return this->activation;
}

void Ability::activateAbility()
{
    this->activation = true;
    this->abilitySprite.setTexture(abilityActiveTexture);
}

void Ability::inactivateAbility()
{
    this->activation = false;
    this->abilitySprite.setTexture(abilityInactiveTexture);
}

void Ability::setInactiveTexture(string inactiveTexturePath)
{
    this->abilityInactiveTexture.loadFromFile(inactiveTexturePath);
}

void Ability::setActiveTexture(string activeTexturePath)
{
    this->abilityActiveTexture.loadFromFile(activeTexturePath);
}

// set position of sprite
void Ability::setPosition(float x, float y)
{
    this->abilitySprite.setPosition(sf::Vector2f(x, y));
}

// show ability icon
void Ability::render(sf::RenderWindow &window)
{
    if (activation)
        this->abilitySprite.setTexture(this->abilityActiveTexture);
    else
        this->abilitySprite.setTexture(this->abilityInactiveTexture);
    window.draw(this->abilitySprite);
}

bool Ability::isAbilitySelected(sf::Vector2f mousePoint)
{
    if (this->abilitySprite.getGlobalBounds().contains(mousePoint))
        return true;
    return false;
}