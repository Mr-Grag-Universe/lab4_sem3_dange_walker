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

    std::shared_ptr<Obj> read(std::ifstream & file);
};

#endif