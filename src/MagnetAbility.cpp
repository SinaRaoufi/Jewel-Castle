#include "Abilities/MagnetAbility.hpp"

using namespace std;

MagnetAbility::MagnetAbility() : Ability()
{
    Ability::setActiveTexture(ABILITIES_TEXTURE_DIRECTORY + string("magnet_active.png"));
    Ability::setInactiveTexture(ABILITIES_TEXTURE_DIRECTORY + string("magnet_inactive.png"));
}