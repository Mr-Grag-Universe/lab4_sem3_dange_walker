#ifndef WALL_CLASS
#define WALL_CLASS

#include "Object.hpp"
#include "Env.hpp"

class Wall : public Environment {
public:
    ObjectType get_type() {
        return WALL;
    }

    Wall() {}
    Wall(std::string n, std::pair<unsigned int, unsigned int> p) {
        position = p;
        name = n;
    }
    ~Wall() {}
protected:
private:
};

#endif