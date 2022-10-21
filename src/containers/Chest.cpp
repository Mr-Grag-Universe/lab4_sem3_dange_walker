#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "../Object.hpp"
#include "Chest.hpp"

Chest::Chest(std::string n, std::pair<unsigned int, unsigned int> p, size_t _id, size_t m_w) : Box(n, p, _id, m_w) {}
void Chest::fill(std::vector <std::unique_ptr<Obj>> _store) {
    for (size_t i = 0, l = _store.size(); i < l; ++i) {}
        // store.push_back(std::make_unique<Obj>(*_store[i]));
}