#ifndef SWARD_CLASS
#define SWARD_CLASS

#include <iostream>
#include <string>
#include <algorithm>

#include "Weapon.hpp"

class Sward : public Weapon {
private:
    /* data */
public:
    ObjectType get_type() { return SWARD; }
    Sward(std::string name, std::pair<unsigned int, unsigned int> position);
    ~Sward();
};

Sward::Sward(std::string n, std::pair<unsigned int, unsigned int> p) {
    name = n;
    position = p;
}

Sward::~Sward() {
}


#endif