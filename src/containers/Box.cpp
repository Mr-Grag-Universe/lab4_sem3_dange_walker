#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "Object.hpp"
#include "Box.hpp"

void Box::push(std::shared_ptr<GameObj> obj) {
    store.push_back(obj);
}

std::vector <std::shared_ptr<GameObj>> Box::extract_all() {
    return std::move(store);
}