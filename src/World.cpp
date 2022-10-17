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
#include "environment/Floor.hpp"
#include "environment/Door.hpp"
#include "environment/Wall.hpp"
#include "alive_obj/Character.hpp"

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
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string name;
    std::vector <std::unique_ptr<Obj>> v;
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
        obj->set_texture(source_file_name, position, position_in, scale);
        v.push_back(std::move(obj));
    }

    file.close();

    return v;
}

void World::add_character(const std::string & file_name) {
    if (file_name.empty()) {
        std::cout << "empty name of file with char sprite" << std::endl;
        throw std::invalid_argument("file does not exist");
    }
    std::ifstream file;
    file.open(file_name);
    std::string name;
    std::string src_file_name;
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    try {
        file >> name;
        file >> src_file_name;
        file >> x_in >> y_in;
        file >> width >> height;
    } catch (...) {
        std::cout << "cannot read data about char" << std::endl;
        throw std::runtime_error("file reading error");
    }

    hero.set_position(std::make_pair(WIDTH/2, HEIGHT/2));
    std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
    std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);
    
    hero.set_texture(src_file_name, std::make_pair(WIDTH/2, HEIGHT/2), position_in, scale);
}

void World::interraction(sf::Event & event) {
    return;
}

//Map create_map() const {
    // Map map(*this);

//    return map;
//}

void World::iterate() {
    return;
}