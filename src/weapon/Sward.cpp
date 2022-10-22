#include "Sward.hpp"

std::unique_ptr<Obj> Sward::read(std::ifstream & file) {
    file >> damage;
    file >> radius;
}