#ifndef DOOR_CLASS
#define DOOR_CLASS

#include "Object.hpp"
#include "Env.hpp"

class Door : public Environment {
public:
    ObjectType get_type()
    { return DOOR; }

    Door() {}
    Door(std::string n, std::pair<unsigned int, unsigned int> p) {
        this->position = p;
        this->name = n;
    }
    ~Door() {}
    
    // void set_texture(std::string , std::pair<unsigned int, unsigned int> , std::pair<unsigned int, unsigned int> p);

    void read(std::ifstream & file);
};

#endif