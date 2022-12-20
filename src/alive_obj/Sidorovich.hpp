#ifndef SIDOROVICH_CLASS
#define SIDOROVICH_CLASS

#include "Trader.hpp"
#include "Character.hpp"

class Sidorovich : public Trader {
protected:
    std::string name = "Sidorovich";
public:
    Sidorovich() {
        health = 5000;
        attitude = GOOD;
        collider.mobility = true;
    }
    ~Sidorovich() {}

    //=============== getters ===============//

    int get_exp_for_kill() const override
    { return 10000; }

    GameTypeSystem get_type() const override
    { return SIDOROVICH; }

    const std::string & get_name() const override
    { return name; }

    //=============== setters ===============//

    //============ other methods ============//
    
    void read(std::ifstream & file) override;
    void iterate(World & w) override;
    void dialog(World & w) override;
    void give_quest(World & w) override;
};

#endif // SIDOROVICH_CLASS