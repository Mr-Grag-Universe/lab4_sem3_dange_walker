#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// #include "../Object.hpp"
#include "BackPack.hpp"
#include "../World.hpp"
#include "../constants.hpp"

BackPack::BackPack(std::string n, std::pair<unsigned int, unsigned int> p, size_t _id, size_t m_w) : Box(n, p, _id, m_w) {}
BackPack::BackPack(std::string n, std::pair<unsigned int, unsigned int> p) {
    name = n;
    position = p;
}
void BackPack::fill(std::vector <std::shared_ptr<GameObj>> _store) {
    // for (size_t i = 0, l = _store.size(); i < l; ++i)
    //     store.push_back(std::move(_store[i]));
    store = std::move(_store);
}

void BackPack::read(std::ifstream & file) {
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    unsigned int number{};
    std::string source_file_name;
    std::string n;
    size_t id{};
    size_t max_weight{};

    file >> name;
    file >> id;
    file >> max_weight;
    file >> x >> y;
    file >> x_in >> y_in;
    file >> width >> height;
    file >> source_file_name;
    file >> number;

    size = std::make_pair(width, height);
    std::pair<unsigned int, unsigned int> p = std::make_pair(x, y);
    // std::pair <unsigned int, unsigned int> p_in = std::make_pair(x_in, y_in);
    // std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

    std::vector <std::shared_ptr<GameObj>> store;
    
    for (size_t i = 0; i < number; ++i) {
        std::string type;
        file >> type;
        // file >> n;

        std::shared_ptr<GameObj> obj = World::load_object(type, file);
        store.push_back(std::move(obj));
    }

    this->fill(std::move(store));
    // this->set_texture(source_file_name, p_in, scale, std::make_pair(1, 1));
    position = p;
}