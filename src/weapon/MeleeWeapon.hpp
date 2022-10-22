#ifndef MELEE_WEAPON
#define MELEE_WEAPON

#include "Weapon.hpp"

class MeleeWeapon : public Weapon{
protected:
    int damage = 0;
    size_t radius = 0;
public:
    MeleeWeapon() {}
};


#endif