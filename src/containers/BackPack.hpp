#ifndef BACKPACK_CLASS
#define BACKPACK_CLASS

#include "Box.hpp"

class BackPack : public Box {
private:
protected:
public:
    BackPack() {}
    BackPack(std::string n, std::pair<unsigned int, unsigned int> p, size_t id, size_t m_w);
    BackPack(std::string n, std::pair<unsigned int, unsigned int> p);
    ~BackPack() {}

    void fill(std::vector <std::shared_ptr<Obj>> store) override;
    void read(std::ifstream & file) override;
    ObjectType get_type() override
    { return BACKPACK; }
};

#endif