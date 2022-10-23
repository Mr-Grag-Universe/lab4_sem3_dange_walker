#ifndef FLOOR_CLASS
#define FLOOR_CLASS

#include "Object.hpp"
#include "Env.hpp"

class Floor : public Environment {
public:
    ObjectType get_type() {
        return FLOOR;
    }
    // void set_texture(std::string , std::pair<unsigned int, unsigned int> , std::pair<unsigned int, unsigned int> p);

    Floor() {}
    Floor(std::string n, std::pair<unsigned int, unsigned int> p) {
        position = p;
        name = n;
        layer = 0;
    }
    ~Floor() {}
    void read(std::ifstream & file);
protected:
private:
};

#endif