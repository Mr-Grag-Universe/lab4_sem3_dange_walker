#ifndef BOX_CLASS
#define BOX_CLASS

#include <iostream>

#include "../Object.hpp"
#include "Container.hpp"

class Box : public Obj<GameTypeSystem>, public Container {
private:
public:
    Box() {}
    Box(std::string n, std::pair<unsigned int, unsigned int> p, size_t _id, size_t m_w) {
        id = _id;
        max_weight = m_w;
        name = n;
        position = p;
    }
    // virtual ~Box() = 0;
    void push(std::shared_ptr<Obj<GameTypeSystem>> obj);
};

#endif