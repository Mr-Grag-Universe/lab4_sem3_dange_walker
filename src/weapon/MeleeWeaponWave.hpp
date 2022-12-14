#ifndef MELEE_WEAPON_WAVE_HPP
#define MELEE_WEAPON_WAVE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "../alive_obj/Alive.hpp"
#include "GameObject.hpp"
#include "../Effect.hpp"
#include "../World.hpp"
#include "../constants.hpp"

class MW_Wave : public Effect {
protected:
    double radius = 0;
    Alive & originator;
    double damage = 0;
public:
    bool makes_damage() const override
    { return true; }
    const Alive & get_originator_ptr() const override
    { return originator; }
    GameTypeSystem get_type() const override
    { return MW_WAVE; }
    void read(std::ifstream & file) override {
    }
    void make_damage(Alive & a) override {
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

    MW_Wave(double r, Alive & o, double d) : originator(o) {
        // textures.current_texture = w.get_effect_texture(MW_WAVE).textures[0];
        radius = r;
        originator = o;
        damage = d;
    }
    MW_Wave(Alive & o) : originator(o) {}
    ~MW_Wave() {}

    void iterate() override {
        position = originator.get_position();
    }
};

#endif