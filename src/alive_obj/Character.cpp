#include "Character.hpp"

std::shared_ptr<Obj> Character::read(std::ifstream & file) {
    std::shared_ptr<Obj> res = std::make_shared<Character>();
    return res;
}