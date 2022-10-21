#ifndef CHEST_CLASS
#define CHEST_CLASS

#include <iostream>
#include <string>
#include <algorithm>

#include "Box.hpp"

class Chest : public Box {
private:
    // ObjectType type = CHEST;
public:
    ObjectType get_type() {
        return DOOR;
    }
    Chest(std::string name, std::pair<unsigned int, unsigned int> p, size_t id, size_t m_w);
    ~Chest() {
        
    }

    void fill(std::vector <std::unique_ptr<Obj>> store);
};

#endif