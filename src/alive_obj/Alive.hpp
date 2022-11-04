#ifndef ALIVE_CLASS
#define ALIVE_CLASS

#include <string>
#include <iostream>

#include "../Object.hpp"

class Alive : public Obj {
protected:
    std::string name;
    double health = 100;
    size_t visibility_radius = 400;
public:
    ObjectType get_type();
    double get_helth()
    { return health; }
    size_t get_visability_radius()
    { return visibility_radius; }

    void set_health(double new_h) { health = new_h; }

    Alive() {

    }
    ~Alive() {

    }
};


#endif