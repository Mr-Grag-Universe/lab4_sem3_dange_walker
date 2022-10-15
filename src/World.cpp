#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "World.hpp"
#include "Map.hpp"
#include "Object.hpp"
#include "Floor.hpp"

std::map <std::string, Obj::ObjectType> types = {
    { "floor",  Obj::FLOOR },
    { "door" ,  Obj::DOOR  },
    { "wall" ,  Obj::WALL  },
};

std::unique_ptr<Obj> World::use_constructor(std::string name, std::pair<unsigned int, unsigned int> position) {
    switch (types[name]) {
    case Obj::FLOOR:
        return std::make_unique<Floor>();
    case Obj::DOOR:
        return std::make_unique<Door>();
    case Obj::WALL:
        return std::make_unique<Wall>();
    default:
        break;
    }
    return nullptr;
}

std::vector <std::unique_ptr<Obj>> World::load_things_from_file(const std::string & file_name) {
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::vector <std::unique_ptr<Obj>> v;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string name;
    std::pair<unsigned int, unsigned int> position;
    while (file >> name) {
        std::cout << name << " ";
        unsigned int x{}, y{};
        file >> x >> y;
        position = std::make_pair(x, y);
        v.push_back(use_constructor(name, position));
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