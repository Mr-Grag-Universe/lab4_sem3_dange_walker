#ifndef WEAPON_CLASS
#define WEAPON_CLASS

#include "../Object.hpp"
#include "../world.hpp"
#include "../alive_obj/Alive.hpp"
#include "../Effect.hpp"

class Weapon : public Obj {
protected:
    size_t recharge_time = 0;
public:
    Weapon() {}
    ~Weapon() {}

    virtual std::shared_ptr<Effect> use(World & w, Alive & o) = 0;
};

#endif // WEAPON