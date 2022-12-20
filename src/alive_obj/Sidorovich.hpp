#ifndef SIDOROVICH_CLASS
#define SIDOROVICH_CLASS

#include "Trader.hpp"

class Sidorovich : public Trader {
protected:
public:
    Sidorovich() {}
    ~Sidorovich() {}

    //=============== getters ===============//

    int get_exp_for_kill() const override
    { return 10000; }
    GameTypeSystem get_type() const override
    { return SIDOROVICH; }

    //=============== setters ===============//

    //============ other methods ============//
    
    void read(std::ifstream & file) override;
    void iterate(World & w) override;
};

#endif // SIDOROVICH_CLASS