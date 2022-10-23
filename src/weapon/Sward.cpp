#include "Sward.hpp"


Sward::Sward(std::string n, int d) {
    name = n;
    damage = d;
}
Sward::Sward(std::string n, std::pair<unsigned int, unsigned int> p) {
    position = p;
    name = n;
}

std::shared_ptr<Obj> Sward::read(std::ifstream & file) {
    file >> name;
    file >> damage;
    file >> radius;

    std::shared_ptr<Obj> res = std::make_shared<Sward>();
    return res;
}