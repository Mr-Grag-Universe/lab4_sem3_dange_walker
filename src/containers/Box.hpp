#ifndef BOX_CLASS
#define BOX_CLASS

#include <iostream>

#include "../objects/Object.hpp"
#include "Container.hpp"

class Box : public GameObj, public Container {
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
    void push(std::shared_ptr<GameObj> obj);
    const std::vector <std::shared_ptr<GameObj>> & get_things() const
    { return store; }
    std::vector <std::shared_ptr<GameObj>> extract_all();
};

#endif