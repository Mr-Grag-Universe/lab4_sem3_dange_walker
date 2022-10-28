#ifndef SLIME_CLASS_HPP
#define SLiMA_CLASS_HPP

#include "NPC.hpp"

class Slime : public NPC {
protected:
    
public:
    Slime() {
        health = 10;
        attitude = BAD;
    }
    ~Slime() {}

    void read(std::ifstream & file) override;
    ObjectType get_type() override
    { return SLIME; }
    void draw(sf::RenderWindow & window);
};

#endif