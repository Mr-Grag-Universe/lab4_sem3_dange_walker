#ifndef CHEST_CLASS
#define CHEST_CLASS

#include <iostream>
#include <string>
#include <algorithm>

#include "Box.hpp"

class Chest : public Box {
private:
public:
    Chest() {}
    Chest(std::string n, std::pair<unsigned int, unsigned int> p, size_t id, size_t m_w);
    Chest(std::string n, std::pair<unsigned int, unsigned int> p);
    ~Chest() {}

    void fill(std::vector <std::shared_ptr<GameObj>> store) override;
    void read(std::ifstream & file) override;
    GameTypeSystem get_type() const override
    { return CHEST; }
};

#endif