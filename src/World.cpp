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
#include "constants.hpp"
#include "environment/Floor.hpp"
#include "environment/Door.hpp"
#include "environment/Wall.hpp"
#include "alive_obj/Character.hpp"
#include "containers/Box.hpp"
#include "containers/Chest.hpp"
#include "weapon/Sward.hpp"

World::World(const std::string & file_name) : World() {
    this->all_things = load_things_from_file(file_name);
    for (size_t i = 0, l = all_things.size(); i < l; ++i) {
        switch (all_things[i]->get_type()) {
        case FLOOR:
            env.floor.push_back((std::shared_ptr<Floor> *) &all_things[i]);
            break;
        case DOOR:
            env.doors.push_back((std::shared_ptr<Door> *) &all_things[i]);
            break;
        case WALL:
            env.walls.push_back((std::shared_ptr<Wall> *) &all_things[i]);
            break;
        default:
            break;
        }
    }
}
World::World(std::vector <std::shared_ptr<Obj>> things) : World() {
    all_things = std::move(things);
}

std::shared_ptr<Obj> World::load_object(std::string type, std::ifstream & file) {
    std::shared_ptr<Obj> obj;
    switch (types[type]) {
        case FLOOR: {
            obj = std::make_shared<Floor>();
            break;
        }
        case DOOR: {
            obj = std::make_shared<Door>();
            break;
        }
        case WALL:
            obj = std::make_shared<Wall>();
            break;
        case CHEST: {
            obj = std::make_shared<Chest>();
            break;
        }
        case SWARD:
            obj = std::make_shared<Sward>();
            break;
        default:
            break;
    }
    obj->read(file);
    return obj;
}

std::vector <std::shared_ptr<Obj>> World::load_things_from_file(const std::string & file_name) {
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    std::vector <std::shared_ptr<Obj>> v;
    while (file >> type) {
        if (type.substr(0, 2) == "//") {
            std::cout << type << "\n";
            continue;
        }
        std::cout << "object type: " << type << "\n";
        /*for (size_t i = 0; i < number; ++i) {
            std::pair<unsigned int, unsigned int> position = std::make_pair(x+i*width, y);
            std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
            std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

            std::shared_ptr<Obj> obj = load_object(name, file);
            obj->set_texture(source_file_name, position_in, scale);
            obj->set_position(position);
            v.push_back(std::move(obj));
        }*/
        v.push_back(load_object(type, file));
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
    
    hero.set_texture(src_file_name, position_in, scale, std::make_pair(1, 1));
    hero.set_sprite_position(std::make_pair(W/2, H/2));
    std::cout << "initial hero position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
    // hero.tesetOutlineThickness(10);
    file.close();
}

void World::interraction(sf::Event & event) {
    switch (event.type) {
    case sf::Event::KeyPressed: {
        // std::cout << "moving" << std::endl;
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

void World::add_things_from_file(const std::string & file_name) {
    std::vector <std::shared_ptr<Obj>> things = load_things_from_file(file_name);

    size_t old_len = all_things.size();
    all_things.insert(
        all_things.end(),
        std::make_move_iterator(things.begin()),
        std::make_move_iterator(things.end())
    );

    for (size_t i = 0, l = things.size(); i < l; ++i) {
        switch (all_things[old_len+i]->get_type()) {
        case FLOOR:
            env.floor.push_back((std::shared_ptr<Floor> *) &all_things[old_len+i]);
            break;
        case DOOR:
            env.doors.push_back((std::shared_ptr<Door>  *) &all_things[old_len+i]);
            break;
        case WALL:
            env.walls.push_back((std::shared_ptr<Wall>  *) &all_things[old_len+i]);
            break;
        default:
            break;
        }
    }
}