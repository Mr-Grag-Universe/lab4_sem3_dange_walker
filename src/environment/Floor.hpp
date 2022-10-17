#ifndef FLOOR_CLASS
#define FLOOR_CLASS

#include "Object.hpp"

class Floor : public Obj {
public:
    ObjectType get_type() {
        return FLOOR;
    }
    // void set_texture(std::string , std::pair<unsigned int, unsigned int> , std::pair<unsigned int, unsigned int> p);

    Floor(std::string n, std::pair<unsigned int, unsigned int> p) {
        position = p;
        name = n;
    }
    ~Floor() {
        
    }
protected:
private:
};

#endif