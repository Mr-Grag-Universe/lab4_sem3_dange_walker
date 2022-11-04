#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "../Object.hpp"
#include "Box.hpp"

void Box::push(std::shared_ptr<Obj> obj) {
    store.push_back(obj);
}