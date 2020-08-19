#ifndef ABILITY_IG
#define ABILITY_IG

#include <SFML/Graphics.hpp>
#include <string>
#include "configs.hpp"

enum abilityStates
{
    NONE = -1,
    MAGNET,
    FIST,
    BOMB
};

class Ability
{
public:
    Ability();
    virtual ~Ability() = 0;
    bool isAbilityActive() const;
    void activateAbility();
    void inactivateAbility();
    void setInactiveTexture(std::string);
    void setActiveTexture(std::string);
    void setPosition(float, float);
    void render(sf::RenderWindow &);
    bool isAbilitySelected(sf::Vector2f);

private:
    sf::Sprite abilitySprite;
    sf::Texture abilityInactiveTexture;
    sf::Texture abilityActiveTexture;
    bool activation;
};

#endif