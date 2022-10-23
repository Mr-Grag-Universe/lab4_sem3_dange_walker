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
    Sward(std::string n, int d);
    Sward(std::string n, std::pair<unsigned int, unsigned int> p);
    ~Sward() {}

    std::shared_ptr<Obj> read(std::ifstream &);
};


#endif