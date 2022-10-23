#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "../Object.hpp"
#include "Chest.hpp"

Chest::Chest(std::string n, std::pair<unsigned int, unsigned int> p, size_t _id, size_t m_w) : Box(n, p, _id, m_w) {}
Chest::Chest(std::string n, std::pair<unsigned int, unsigned int> p) {
    name = n;
    position = p;
}
void Chest::fill(std::vector <std::shared_ptr<Obj>> _store) {
    // for (size_t i = 0, l = _store.size(); i < l; ++i)
    //     store.push_back(std::move(_store[i]));
    store = std::move(_store);
}

std::shared_ptr<Obj> Chest::read(std::ifstream & file) {
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    unsigned int number{};
    std::string source_file_name;
    std::string n;
    size_t id{};
    size_t max_weight{};

    file >> x >> y;
    file >> x_in >> y_in;
    file >> width >> height;
    file >> source_file_name;
    file >> number;
    file >> name;
    file >> max_weight;
    file >> id;

    std::pair<unsigned int, unsigned int> position = std::make_pair(x, y);
    std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
    std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

    std::shared_ptr<Obj> res = std::make_shared<Chest>();
    return res;
}