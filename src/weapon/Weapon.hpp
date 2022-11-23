#ifndef WEAPON_CLASS
#define WEAPON_CLASS

#include "../objects/GameObject.hpp"
#include "../alive_obj/Alive.hpp"
#include "../constants.hpp"
#include "../Effect.hpp"

class Weapon : public GameObj {
protected:
    size_t recharge_time = 0;
    bool is_using = false;
public:
    void switch_usage()
    { is_using = !is_using; }
    virtual bool is_it_using() const
    { return is_using; }

    Weapon() {}
    ~Weapon() {}

    virtual std::shared_ptr<Effect> use(Alive & o) = 0;
};

#endif // WEAPON