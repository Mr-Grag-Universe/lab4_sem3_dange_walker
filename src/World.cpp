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
        return std::make_unique<Floor>(name, position);
    case Obj::DOOR:
        return std::make_unique<Door>(name, position);
    case Obj::WALL:
        return std::make_unique<Wall>(name, position);
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
    // data format: type | x | y | position_in_file_x | position_in_file_y | width | height | sprite_dir/sprite_file_name.txt
    while (file >> name) {
        std::cout << name << " ";
        unsigned int x{}, y{};
        unsigned int x_in{}, y_in{};
        unsigned int width{}, height{};
        std::string source_file_name;
        file >> x >> y;
        file >> x_in >> y_in;
        file >> width >> height;
        file >> source_file_name;
        std::pair<unsigned int, unsigned int> position = std::make_pair(x, y);
        std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
        std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

        std::unique_ptr<Obj> obj = use_constructor(name, position);
        obj->set_texture(source_file_name, position_in, scale);
        v.push_back(std::move(obj));
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