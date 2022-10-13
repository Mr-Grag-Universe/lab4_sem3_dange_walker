#ifndef MY_WORLD_CLASS
#define MY_WORLD_CLASS

#include <SFML/System.hpp>

#include "Map.hpp"

class World {
private:
    /* data */
public:
    World(/* args */) = default;
    ~World() = default;

    void interraction(sf::Event & event);
    void iterate();
    Map create_map() const;
};

#endif