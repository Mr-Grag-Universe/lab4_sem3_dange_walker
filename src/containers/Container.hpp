#ifndef CONTAINER_CLASS
#define CONTAINER_CLASS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// #include "../Object.hpp"
// #include "../Weapon.hpp"

class Container {
private:
    mutable size_t max_weight = 0;
    std::vector <std::unique_ptr<Obj>> store;
    size_t id = 0;
public:
    Container();
    virtual ~Container() = 0;
};

Container::Container() {
}

#include "Chest.hpp"

#endif