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

    size_t W, H;

    std::vector <std::unique_ptr<Obj>> all_things;
    static std::unique_ptr<Obj> use_constructor(std::string name, std::pair<unsigned int, unsigned int> position);

public:
    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    World() : W(sf::VideoMode::getDesktopMode().size.x), H(sf::VideoMode::getDesktopMode().size.y) {
    }
    World(std::vector <std::unique_ptr<Obj>> things) : World() {
        // this->all_things = things;
    }
    static std::vector <std::unique_ptr<Obj>> load_things_from_file(const std::string & file_name);
    World(const std::string & file_name) : World() {
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
    void add_things_from_file(const std::string & file_name) {
        std::vector <std::unique_ptr<Obj>> things = load_things_from_file(file_name);

        size_t old_len = all_things.size();
        all_things.insert(
            all_things.end(),
            std::make_move_iterator(things.begin()),
            std::make_move_iterator(things.end())
        );

        for (size_t i = 0, l = things.size(); i < l; ++i) {
            switch (things[i]->get_type()) {
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
    ~World() = default;

    void add_character(const std::string & file_name);
    void interraction(sf::Event & event);
    void iterate();

    const Character & get_hero() const {
        // std::cout << "hero position: (" << hero.get_sprite().getPosition().x << ", " << hero.get_position().second << ")\n";
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