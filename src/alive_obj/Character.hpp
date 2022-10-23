#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include "Alive.hpp"

class Character : public Alive {
private:
    /* data */
public:
    ObjectType get_type() override
    { return CHARACTER; }
    Character() {}
    ~Character() {}

    void read(std::ifstream & file) override;
};

#endif