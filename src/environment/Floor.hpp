#ifndef FLOOR_CLASS
#define FLOOR_CLASS

#include "Env.hpp"

class Floor : public Environment {
public:
    GameTypeSystem get_type() const {
        return FLOOR;
    }
    // void set_texture(std::string , std::pair<unsigned int, unsigned int> , std::pair<unsigned int, unsigned int> p);

    Floor() {}
    Floor(std::string n, std::pair<unsigned int, unsigned int> p) {
        position = p;
        name = n;
    }
    ~Floor() {}
protected:
private:
};

#endif