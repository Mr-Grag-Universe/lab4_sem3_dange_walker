#ifndef SKIN_CLASS
#define SKIN_CLASS

#include "BPMObject.hpp"
#include "../constants.hpp"

class Skin : public BPMObj {
public:
    Skin() {}
    Skin(std::string n, pair_ui64_t p) {
        position = p;
        name = n;
    }
    BackPackTypeSystem get_type() const override
    { return SKIN; }
    void read(std::ifstream & ) override {
    }
    void draw(sf::RenderWindow & window) {}
};

#endif