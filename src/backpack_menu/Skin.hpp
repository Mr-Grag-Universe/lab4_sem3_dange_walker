#ifndef SKIN_CLASS
#define SKIN_CLASS

#include "../Object.hpp"
#include "../constants.hpp"

class Skin : public Obj<BackPackTypeSystem> {
public:
    Skin() {}
    Skin(std::string n, pair_ui64_t p) {
        position = p;
        name = n;
    }
    BackPackTypeSystem get_type() override
    { return SKIN; }
    void read(std::ifstream & ) override {
    }
};

#endif