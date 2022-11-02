#ifndef MELEE_WEAPON
#define MELEE_WEAPON

#include "Weapon.hpp"
#include "World.hpp"
#include "MeleeWeaponWave.hpp"

class MeleeWeapon : public Weapon {
protected:
    int damage = 0;
    size_t radius = 0;
public:
    MeleeWeapon() {}
    ~MeleeWeapon() {}
    virtual MW_Wave wave() = 0;
};


#endif