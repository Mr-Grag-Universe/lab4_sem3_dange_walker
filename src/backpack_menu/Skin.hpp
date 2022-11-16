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
    Skin(const Skin && s) {
        position = s.position;
        name = s.name;
        texture = s.texture;
        sprite = s.sprite;
        layer = s.layer;
    }
    Skin(const Skin & s) {
        position = s.position;
        name = s.name;
        texture = s.texture;
        sprite = s.sprite;
        layer = s.layer;
    }
    BackPackTypeSystem get_type() const override
    { return SKIN; }
    void read(std::ifstream & ) override {
    }
    void draw(sf::RenderWindow & window) {
        window.draw(sprite);
    }
private:
    BackPackTypeSystem type = SKIN;
};

#endif