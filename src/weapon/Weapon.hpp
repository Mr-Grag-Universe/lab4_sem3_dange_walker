#ifndef WEAPON_CLASS
#define WEAPON_CLASS

#include "../Object.hpp"
#include "../world.hpp"
#include "../alive_obj/Alive.hpp"
#include "../constants.hpp"

class Weapon : public Obj<GameTypeSystem> {
protected:
    size_t recharge_time = 0;
public:
    Weapon() {}
    ~Weapon() {}

    virtual std::shared_ptr<Effect> use(World<GameTypeSystem> & w, Alive & o) = 0;
};

#endif // WEAPON