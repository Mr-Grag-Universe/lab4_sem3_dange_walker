#include <vector>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "World.hpp"
#include "Map.hpp"
#include "Object.hpp"

std::vector <Obj> World::load_things_from_file(const std::string & file_name) {
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::vector <Obj> v;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string buf;
    std::pair<unsigned int, unsigned int> position;
    while (file >> buf) {
        std::cout << buf << " ";
        unsigned int x{}, y{};
        file >> x >> y;
        position = std::make_pair(x, y);
        // v.push_back();
    }

    file.close();


    return v;
}

void World::interraction(sf::Event & event) {
    return;
}

Map World::create_map() const {
    Map map;
    return map;
}

void World::iterate() {
    return;
}