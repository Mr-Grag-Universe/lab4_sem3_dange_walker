#ifndef MELEE_WEAPON
#define MELEE_WEAPON

#include "Weapon.hpp"
#include "World.hpp"
#include "MeleeWeaponWave.hpp"

class MeleeWeapon : public Weapon {
protected:
    double damage = 0;
    size_t radius = 0;
public:
    double get_damage()
    { return damage; }
    MeleeWeapon() {}
    ~MeleeWeapon() {}
    virtual MW_Wave wave(World & w, double r, Alive& o) = 0;
};


#endif