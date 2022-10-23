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

    std::shared_ptr<Obj> read(std::ifstream & file) override;
};

#endif