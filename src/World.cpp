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

std::map <std::string, Obj::ObjectType> types = {
    { "floor",  Obj::FLOOR },
    { "door" ,  Obj::DOOR  },
    { "wall" ,  Obj::WALL  },
    { "chest",  Obj::CHEST },
    { "sward",  Obj::SWARD },
};

World::World(const std::string & file_name) : World() {
    this->all_things = load_things_from_file(file_name);
    for (size_t i = 0, l = all_things.size(); i < l; ++i) {
        switch (all_things[i]->get_type()) {
        case Obj::FLOOR:
            env.floor.push_back((std::unique_ptr<Floor> *) &all_things[i]);
            break;
        case Obj::DOOR:
            env.doors.push_back((std::unique_ptr<Door> *) &all_things[i]);
            break;
        case Obj::WALL:
            env.walls.push_back((std::unique_ptr<Wall> *) &all_things[i]);
            break;
        default:
            break;
        }
    }
}
World::World(std::vector <std::unique_ptr<Obj>> things) : World() {
    all_things = std::move(things);
}

std::unique_ptr<Obj> World::use_constructor(std::string name, std::pair<unsigned int, unsigned int> position) {
    switch (types[name]) {
    case Obj::FLOOR:
        return std::make_unique<Floor>(name, position);
    case Obj::DOOR:
        return std::make_unique<Door>(name, position);
    case Obj::WALL:
        return std::make_unique<Wall>(name, position);
    case Obj::SWARD:
        return std::make_unique<Sward>(name, position);
    default:
        break;
    }
    return nullptr;
}

std::unique_ptr<Box> create_box(std::string type, std::string name, std::pair<unsigned int, unsigned int> p, size_t id, size_t max_weight) {
    switch (types[type]) {
    case Obj::CHEST:
        return std::make_unique<Chest>(name, p, id, max_weight);
    
    default:
        return std::make_unique<Chest>(name, p, id, max_weight);
    }
    return std::make_unique<Chest>(name, p, id, max_weight);
}

std::unique_ptr<Weapon> create_weapon(std::string weapon_type, int damage) {
    switch (types[weapon_type]) {
    case Obj::SWARD:
        return std::make_unique<Sward>(weapon_type, damage);
    default:
        return std::make_unique<Sward>(weapon_type, damage);
    }
    return std::make_unique<Sward>(weapon_type, damage);
}

std::vector <std::unique_ptr<Obj>> World::load_things_from_file(const std::string & file_name) {
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }
    unsigned int x{}, y{};
    unsigned int x_in{}, y_in{};
    unsigned int width{}, height{};
    unsigned int number{};
    std::string source_file_name;

    std::string name;
    std::vector <std::unique_ptr<Obj>> v;
    // data format: type | x | y | position_in_file_x | position_in_file_y | width | height | sprite_dir/sprite_file_name.txt
    while (file >> name) {

        if (name.substr(0, 2) == "//") {
            std::cout << name << "\n";
            // file >> name;
            continue;
        }
        std::cout << "object name: " << name << "\n";
        file >> x >> y;
        file >> x_in >> y_in;
        file >> width >> height;
        file >> source_file_name;
        file >> number;
        if (name == "container") {
            file >> name;
            size_t max_weight{};
            file >> max_weight;
            size_t id{};
            file >> id;

            std::pair<unsigned int, unsigned int> position = std::make_pair(x, y);
            std::pair <unsigned int, unsigned int> position_in = std::make_pair(x_in, y_in);
            std::pair <unsigned int, unsigned int> scale = std::make_pair(width, height);

            std::vector <std::unique_ptr<Obj>> store;
            
            for (size_t i = 0; i < number; ++i) {
                std::string weapon_type;
                file >> weapon_type;
                int damage{};
                file >> damage;

                std::unique_ptr<Obj> obj = create_weapon(weapon_type, damage);
                obj->set_texture(source_file_name, position_in, scale);
                obj->set_position(position);
                store.push_back(std::move(obj));
            }

            std::unique_ptr<Box> b = create_box(name, name, position, id, max_weight);
            b->fill(std::move(store));
            b->set_texture(source_file_name, position_in, scale);
            b->set_position(position);
            v.push_back(std::move(b));

            continue;
        }
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
    std::vector <std::unique_ptr<Obj>> things = load_things_from_file(file_name);

    size_t old_len = all_things.size();
    all_things.insert(
        all_things.end(),
        std::make_move_iterator(things.begin()),
        std::make_move_iterator(things.end())
    );

    for (size_t i = 0, l = things.size(); i < l; ++i) {
        switch (all_things[old_len+i]->get_type()) {
        case Obj::FLOOR:
            env.floor.push_back((std::unique_ptr<Floor> *) &all_things[old_len+i]);
            break;
        case Obj::DOOR:
            env.doors.push_back((std::unique_ptr<Door>  *) &all_things[old_len+i]);
            break;
        case Obj::WALL:
            env.walls.push_back((std::unique_ptr<Wall>  *) &all_things[old_len+i]);
            break;
        default:
            break;
        }
    }
}