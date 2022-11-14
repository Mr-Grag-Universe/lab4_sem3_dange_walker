#ifndef MELEE_WEAPON_WAVE_HPP
#define MELEE_WEAPON_WAVE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "../alive_obj/Alive.hpp"
#include "../Object.hpp"
#include "../Effect.hpp"
#include "../GameWorld.hpp"
#include "../constants.hpp"

class MW_Wave : public Effect {
protected:
    double radius = 0;
    Alive & originator;
    double damage = 0;
public:
    bool makes_damage() const
    { return true; }
    const Alive & get_originator_ptr() const
    { return originator; }
    GameTypeSystem get_type()
    { return MW_WAVE; }
    void read(std::ifstream & file) {
    }
    void make_damage(Alive & a) {
        if (distance((pair_ui64_t) a.get_position(), (pair_ui64_t) position) <= radius) {
            if (a.get_helth() <= damage) {
                a.set_health(0);
                std::cout << "killed" << std::endl;
            }
            else {
                a.set_health(a.get_helth()-damage);
                std::cout << "damaged" << std::endl;
            }
        }
    }
    void update_texture() {
    }

    MW_Wave(World<GameTypeSystem> & w, double r, Alive & o, double d) : Effect(w.get_effect_texture(MW_WAVE)), radius(r), originator(o), damage(d) {
        texture = w.get_effect_texture(MW_WAVE).textures[0];
    }
    MW_Wave(const MW_Wave & w) = default;
    ~MW_Wave() {}
};

#endif