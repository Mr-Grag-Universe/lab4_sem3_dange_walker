#ifndef CONTAINER_CLASS
#define CONTAINER_CLASS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "../Object.hpp"

class Container {
protected:
    size_t max_weight = 0;
    std::vector <std::shared_ptr<Obj<GameTypeSystem>>> store;
    size_t id = 0;
public:
    Container() {}
    Container(size_t _id, size_t m_w) : max_weight(m_w), id(_id) {}
    // ~Container() = default;
    virtual void fill(std::vector <std::shared_ptr<Obj<GameTypeSystem>>> store) = 0;
    virtual void push(std::shared_ptr<Obj<GameTypeSystem>>) = 0;
};

#endif