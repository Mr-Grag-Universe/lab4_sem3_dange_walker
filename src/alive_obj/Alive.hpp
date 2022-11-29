#ifndef ALIVE_CLASS
#define ALIVE_CLASS

#include <string>
#include <iostream>

#include "../objects/GameObject.hpp"

class Alive : public GameObj {
protected:
    std::string name;
    double health = 100;
    double max_health = 100;
    double visibility_radius = 400;
public:
    GameTypeSystem get_type() const override
    { return ALIVE; }
    double get_helth() const 
    { return health; }
    size_t get_visability_radius()
    { return visibility_radius; }
    double get_max_health() const
    { return max_health; }
    void set_max_health(double m_h)
    { max_health = m_h; }

    void set_health(double new_h) { health = new_h; }

    Alive() {

    }
    ~Alive() {

    }
};


#endif