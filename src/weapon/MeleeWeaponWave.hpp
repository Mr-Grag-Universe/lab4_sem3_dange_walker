#ifndef MELEE_WEAPON_WAVE_HPP
#define MELEE_WEAPON_WAVE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "../alive_obj/Alive.hpp"
#include "../Object.hpp"
#include "../Effect.hpp"
#include "../World.hpp"

class MW_Wave : public Effect {
protected:
    double radius = 0;
    Alive & originator;
public:
    ObjectType get_type()
    { return MW_WAVE; }
    void read(std::ifstream & file) {
        
    }

    MW_Wave(World & w, double r, Alive & o) : radius(r), originator(o) {
        texture = w.get_effect_texture(MW_WAVE);
    }
    MW_Wave(const MW_Wave & w) = default;
    ~MW_Wave() {}
};

#endif