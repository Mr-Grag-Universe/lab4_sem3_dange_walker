#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include "Alive.hpp"

class Character : public Alive {
private:
    /* data */
public:
    ObjectType get_type() {
        return CHARACTER;
    }
    Character() {

    }
    ~Character() {

    }
};

#endif