#ifndef CONTAINER_CLASS
#define CONTAINER_CLASS

#include <vector>
#include <set>

#include "Object.hpp"
#include "Weapon.hpp"

class Container {
private:
    std::vector <Weapon> weapons;
public:
    Container(/* args */);
    ~Container();
};

Container::Container(/* args */) {
}

Container::~Container() {
}

// шаблон класса?
class Thing {
private:
};

#endif