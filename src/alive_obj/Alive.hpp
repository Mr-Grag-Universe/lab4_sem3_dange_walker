#ifndef ALIVE_CLASS
#define ALIVE_CLASS

#include <string>
#include <iostream>

#include "../objects/GameObject.hpp"

class Alive : public GameObj {
protected:
    std::string name;
    double health = 100;
    size_t visibility_radius = 400;
public:
    GameTypeSystem get_type() const override
    { return ALIVE; }
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