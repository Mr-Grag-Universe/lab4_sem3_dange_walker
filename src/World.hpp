#ifndef MY_WORLD_CLASS
#define MY_WORLD_CLASS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include <SFML/System.hpp>

// #include "Map.hpp"
#include "containers/Chest.hpp"
#include "Object.hpp"
#include "environment/Wall.hpp"
#include "environment/Door.hpp"
#include "environment/Floor.hpp"
#include "alive_obj/Character.hpp"

class World {
private:
    struct Env {
        std::vector <std::unique_ptr<Wall>*>  walls;
        std::vector <std::unique_ptr<Floor>*> floor;
        std::vector <std::unique_ptr<Door>*>  doors;
    };

    Character hero;
    Env env;

    std::vector <std::unique_ptr<Obj>> all_things;
    static std::unique_ptr<Obj> use_constructor(std::string name, std::pair<unsigned int, unsigned int> position);

public:
    World(/* args */) = default;
    World(std::vector <std::unique_ptr<Obj>> things) {
        // this->all_things = things;
    }
    static std::vector <std::unique_ptr<Obj>> load_things_from_file(const std::string & file_name);
    World(const std::string & file_name) {
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
    ~World() = default;

    void add_character(const std::string & file_name);
    void interraction(sf::Event & event);
    void iterate();

    const Character & get_hero() const {
        return hero;
    }
    const std::vector <std::unique_ptr<Obj>> & get_all_things() const {
        return all_things;
    }
    const Env & get_env() const {
        return env;
    }
};

#endif