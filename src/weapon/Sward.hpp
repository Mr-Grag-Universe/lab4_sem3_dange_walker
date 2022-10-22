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
    // constructors
    Sward(std::string n, int d);
    Sward(std::string n, std::pair<unsigned int, unsigned int> p);
    ~Sward();

    std::unique_ptr<Obj> read(std::ifstream &);
};

Sward::Sward(std::string n, int d) {
    name = n;
    damage = d;
}
Sward::Sward(std::string n, std::pair<unsigned int, unsigned int> p) {
    position = p;
    name = n;
}

Sward::~Sward() {
}


#endif