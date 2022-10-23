#include "Sward.hpp"


Sward::Sward(std::string n, int d, size_t r) {
    name = n;
    damage = d;
    radius = r;
}
Sward::Sward(std::string n, std::pair<unsigned int, unsigned int> p) {
    position = p;
    name = n;
}

void Sward::read(std::ifstream & file) {
    file >> name;
    file >> damage;
    file >> radius;

    std::shared_ptr<Obj> res = std::make_shared<Sward>(name, damage, radius);
    // return res;
}