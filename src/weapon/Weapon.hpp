#ifndef WEAPON_CLASS
#define WEAPON_CLASS

#include "../Object.hpp"

class Weapon : public Obj {
protected:
    size_t recharge_time = 0;
public:
    Weapon() {}
    ~Weapon() {}
};

#endif // WEAPON