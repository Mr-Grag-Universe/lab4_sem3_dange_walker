#ifndef TRADER_CLASS_HPP
#define TRADER_CLASS_HPP

#include "NPC.hpp"

class Trader : public NPC {
private:
protected:
public:
    virtual void give_quest(World & w) = 0;
};

#endif // TRADER_CLASS_HPP