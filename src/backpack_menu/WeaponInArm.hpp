#ifndef WEAPON_IN_ARM_CLASS
#define WEAPON_IN_ARM_CLASS

#include "BPMObject.hpp"
#include "../constants.hpp"

class WeaponInArm : public BPMObj {
public:
    WeaponInArm() {}
    WeaponInArm(std::string n, pair_ui64_t p) {
        position = p;
        name = n;
    }
    BackPackTypeSystem get_type() const override
    { return WEAPON_IN_ARMS; }
    void read(std::ifstream & ) override {
    }
    void draw(sf::RenderWindow & window) const override {
        window.draw(sprite);
    }
private:
    [[maybe_unused]] BackPackTypeSystem type = WEAPON_IN_ARMS;
};

#endif