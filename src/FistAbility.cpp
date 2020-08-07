#include "Abilities/FistAbility.hpp"

using namespace std;

FistAbility::FistAbility() : Ability()
{
    Ability::setActiveTexture(ABILITIES_TEXTURE_DIRECTORY + string("fist_active.png"));
    Ability::setInactiveTexture(ABILITIES_TEXTURE_DIRECTORY + string("fist_inactive.png"));
}