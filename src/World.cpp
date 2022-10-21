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
#include "containers/Chest.hpp"

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
        if (name == "//") continue;
        if (name == "container") {
            file >> name;
            size_t id{};
            file >> id;
            std::string weapon_type;
            file >> weapon_type;
            int damage{};
            file >> damage;
            continue;
        }
        unsigned int x{}, y{};
        unsigned int x_in{}, y_in{};
        unsigned int width{}, height{};
        unsigned int number{};
        std::string source_file_name;
        file >> x >> y;
        file >> x_in >> y_in;
        file >> width >> height;
        file >> source_file_name;
        file >> number;
        for (size_t i = 0; i < number; ++i) {
            std::pair<unsigned int, unsigned int> position = std::make_pair(x+i*width, y);
            std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
            std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

            std::unique_ptr<Obj> obj = use_constructor(name, position);
            obj->set_texture(source_file_name, position_in, scale);
            obj->set_position(position);
            v.push_back(std::move(obj));
        }
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

    hero.set_position(std::make_pair(W/2, H/2));
    std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
    std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);
    
    hero.set_texture(src_file_name, position_in, scale);
    hero.set_sprite_position(std::make_pair(W/2, H/2));
    std::cout << "initial hero position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
    // hero.tesetOutlineThickness(10);
}

void World::interraction(sf::Event & event) {
    switch (event.type) {
    case sf::Event::KeyPressed: {
        std::cout << "moving" << std::endl;
        if (event.key.code == sf::Keyboard::A) {
            std::cout << "move left" << std::endl;
            hero.move(-10, 0);
            std::cout << "new_hero_position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
        } else if (event.key.code == sf::Keyboard::D) {
            hero.move(10, 0);
        } else if (event.key.code == sf::Keyboard::W) {
            hero.move(0, -10);
        } else if (event.key.code == sf::Keyboard::S) {
            hero.move(0, 10);
        }
        // std::cout << "new hero position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
        break;
    }
    case sf::Event::Resized: {
        W = event.size.width;
        H = event.size.height;
        hero.set_sprite_position(std::make_pair(W/2, H/2));
        std::cout << "new width: " << event.size.width << std::endl;
        std::cout << "new height: " << event.size.height << std::endl;
        break;
    }
    default:
        break;
    }
    return;
}

void World::iterate() {
    return;
}