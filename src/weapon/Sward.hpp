#ifndef SWARD_CLASS
#define SWARD_CLASS

#include <iostream>
#include <string>
#include <algorithm>

#include "MeleeWeapon.hpp"

class Sward : public MeleeWeapon {
private:
    /* data */
public:
    GameTypeSystem get_type() const override
    { return SWARD; }
    // constructors
    Sward() {}
    Sward(std::string n, int d=0, size_t r=0);
    Sward(std::string n, std::pair<unsigned int, unsigned int> p);
    Sward(const Sward & s) = default;
    ~Sward() {}

    void read(std::ifstream &) override;
    std::shared_ptr<Effect> use(Alive & o) override;
    std::shared_ptr<MW_Wave> wave(double r, Alive & o) override;
};


#endif