#ifndef SWARD_CLASS
#define SWARD_CLASS

#include <iostream>
#include <string>
#include <algorithm>

#include "MeleeWeapon.hpp"

class Sward : public MeleeWeapon {
private:
    /* data */
public:
    ObjectType get_type() { return SWARD; }
    Sward(std::string n, int d);
    ~Sward();
};

Sward::Sward(std::string n, int d) {
    name = n;
    damage = d;
}

Sward::~Sward() {
}


#endif