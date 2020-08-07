#include "Abilities/BombAbility.hpp"

using namespace std;

BombAbility::BombAbility() : Ability()
{
    Ability::setActiveTexture(ABILITIES_TEXTURE_DIRECTORY + string("bomb_active.png"));
    Ability::setInactiveTexture(ABILITIES_TEXTURE_DIRECTORY + string("bomb_inactive.png"));
}