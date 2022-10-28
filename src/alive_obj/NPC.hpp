#ifndef NPC_CLASS_HPP
#define NPC_CLASS_HPP

#include "Alive.hpp"

class NPC;

class NPC : public Alive {
public:
    enum Attitude {
        BAD,
        GOOD,
    };
protected:
    Attitude attitude = GOOD;
public:
    NPC() {}
    ~NPC() {}
};

#endif