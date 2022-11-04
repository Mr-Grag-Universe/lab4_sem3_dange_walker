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
    ObjectType get_type()
    { return SWARD; }
    // constructors
    Sward() {}
    Sward(std::string n, int d=0, size_t r=0);
    Sward(std::string n, std::pair<unsigned int, unsigned int> p);
    Sward(const Sward & s) = default;
    ~Sward() {}

    void read(std::ifstream &);
    void use(World & w, Alive & o);
    MW_Wave wave(World & w, double r, Alive & o);
};


#endif