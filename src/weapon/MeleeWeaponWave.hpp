#ifndef MELEE_WEAPON_WAVE_HPP
#define MELEE_WEAPON_WAVE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "../alive_obj/Alive.hpp"
#include "../Object.hpp"
#include "../Effect.hpp"

class MW_Wave : public Obj, public Effect {
protected:
    double radius = 0;
    std::shared_ptr<Alive> originator;
public:
    ObjectType get_type()
    { return MW_WAVE; }
    void read(std::ifstream & file) {}

    MW_Wave(double r, std::shared_ptr<Alive> o) : radius(r), originator(o) {}
    MW_Wave() {}
    ~MW_Wave() {}
};

#endif