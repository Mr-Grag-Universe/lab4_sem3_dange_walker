#ifndef MELEE_WEAPON
#define MELEE_WEAPON

#include "Weapon.hpp"
#include "MeleeWeaponWave.hpp"
// #include "../sfml_classes/sfml_object.hpp"

class MeleeWeapon : public Weapon {
protected:
    double damage = 0;
    size_t radius = 0;
public:
    double get_damage()
    { return damage; }
    MeleeWeapon() {}
    ~MeleeWeapon() {}
    virtual std::shared_ptr<MW_Wave> wave(double r, Alive& o) = 0;
};


#endif