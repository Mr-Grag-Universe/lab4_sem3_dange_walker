#ifndef SLIME_CLASS_HPP
#define SLIME_CLASS_HPP

#include "NPC.hpp"

class Slime : public NPC {
protected:
    
public:
    Slime() {
        health = 10;
        attitude = BAD;
        collider.mobility = true;
    }
    ~Slime() {}

    void read(std::ifstream & file) override;
    GameTypeSystem get_type() override
    { return SLIME; }
    void draw(sf::RenderWindow & window);
};

#endif