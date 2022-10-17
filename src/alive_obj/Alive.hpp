#ifndef ALIVE_CLASS
#define ALIVE_CLASS

#include <string>
#include <iostream>

#include "../Object.hpp"

class Alive : public Obj {
private:
    std::string name;
    // double health = 0;
    // size_t visibility_radius = WIDTH;
public:
    ObjectType get_type();
    Alive() {

    }
    ~Alive() {

    }
};


#endif