#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "backpack_menu.hpp"
#include "World.hpp"
#include "Map.hpp"
#include "Object.hpp"
#include "constants.hpp"
#include "environment/Floor.hpp"
#include "environment/Door.hpp"
#include "environment/Wall.hpp"
#include "alive_obj/Character.hpp"
#include "alive_obj/Slime.hpp"
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
        case SLIME:
            obj = std::make_shared<Slime>();
        default:
            break;
    }
    obj->read(file);
    return obj;
}

std::shared_ptr<NPC> World::load_npc(std::string type, std::ifstream & file) {
    std::shared_ptr<NPC> obj;
    switch (types[type]) {
        case SLIME:
            obj = std::make_shared<Slime>();
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
        v.push_back(load_object(type, file));
    }

    file.close();

    return v;
}

std::vector <std::shared_ptr<NPC>> World::load_npcs_from_file(const std::string & file_name) {
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    std::vector <std::shared_ptr<NPC>> v;
    while (file >> type) {
        if (type.substr(0, 2) == "//") {
            std::cout << type << "\n";
            continue;
        }
        std::cout << "npc type: " << type << "\n";
        if (alive_types.find(types[type]) != alive_types.end())
            v.push_back(load_npc(type, file));
        else
            throw std::runtime_error("this is not npc in file: " + file_name);
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

void World::interraction(sf::Event & event, sf::RenderWindow & window) {
    switch (event.type) {
    case sf::Event::KeyPressed: {
        if (this->mode == RUN) {
            game_interraction(event, window);
        } else if (this->mode == MENU) {
            menu_interraction(event, window);
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
    std::pair <unsigned int, unsigned int> p_h = hero.get_position();
    for (size_t i = 0; i < all_npc.size(); ++i) {
        if (all_npc[i]->get_attitude() == NPC::BAD)
            if (distance(all_npc[i]->get_position(), p_h) < all_npc[i]->get_visability_radius()) {
                all_npc[i]->set_velocity(3);
                std::pair <unsigned int, unsigned int> p_o = all_npc[i]->get_position();
                double d_x = (double) p_h.first - (double) p_o.first;
                double d_y = (double) p_h.second - (double) p_o.second;
                double a = atan(d_y/d_x);
                all_npc[i]->set_v_angle(a);
            }
    }

    for (size_t i = 0; i < all_npc.size(); ++i) {
        if (all_npc[i]->is_mobile()) {
            double v = all_npc[i]->get_velocity();
            if (v == 0)
                continue;
            double a = all_npc[i]->get_v_angle();
            int v_x = v * cos(a);
            int v_y = v * sin(a);
            all_npc[i]->move(v_x, v_y);
        }
    }
    
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

void World::add_npcs_from_file(const std::string & file_name) {
    std::vector <std::shared_ptr<NPC>> npcs = load_npcs_from_file(file_name);

    all_npc.insert(
        all_npc.end(),
        std::make_move_iterator(npcs.begin()),
        std::make_move_iterator(npcs.end())
    );
}