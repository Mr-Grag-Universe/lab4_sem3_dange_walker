#ifndef DOOR_CLASS
#define DOOR_CLASS

#include "Object.hpp"

class Door : public Obj {
public:
    ObjectType get_type()
    { return DOOR; }

    Door(std::string n, std::pair<unsigned int, unsigned int> p) {
        this->position = p;
        this->name = n;
    }

    // void set_texture(std::string , std::pair<unsigned int, unsigned int> , std::pair<unsigned int, unsigned int> p);

    ~Door() {}
};

#endif