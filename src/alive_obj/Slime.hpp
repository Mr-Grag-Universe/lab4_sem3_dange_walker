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
    int get_exp_for_kill() const override
    { return 5; }
    GameTypeSystem get_type() const override
    { return SLIME; }
};

#endif