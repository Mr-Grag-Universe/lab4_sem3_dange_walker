#ifndef SKELETON_CLASS_HPP
#define SKELETON_CLASS_HPP

#include "NPC.hpp"

class Skeleton : public NPC {
protected:
    
public:
    Skeleton() {
        health = 50;
        attitude = BAD;
        collider.mobility = true;
    }
    ~Skeleton() {}

    void read(std::ifstream & file) override;
    int get_exp_for_kill() const override
    { return 80; }
    GameTypeSystem get_type() const override
    { return SKELETON; }
    void iterate(World & w) override;
};

#endif