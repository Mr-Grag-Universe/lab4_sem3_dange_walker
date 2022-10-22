#ifndef BOX_CLASS
#define BOX_CLASS

#include "../Object.hpp"
#include "Container.hpp"

class Box : public Obj, public Container {
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
};

#endif