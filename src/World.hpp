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
    const Character & get_hero() const { return hero; }
    const std::vector <std::unique_ptr<Obj>> & get_all_things() const { return all_things; }
    const Env & get_env() const { return env; }

    void add_things_from_file(const std::string & file_name);
    static std::vector <std::unique_ptr<Obj>> load_things_from_file(const std::string & file_name);

    World() : W(sf::VideoMode::getDesktopMode().size.x), H(sf::VideoMode::getDesktopMode().size.y) {}
    World(std::vector <std::unique_ptr<Obj>> things);
    World(const std::string & file_name);
    ~World() = default;

    void add_character(const std::string & file_name);
    void interraction(sf::Event & event);
    void iterate();
};

#endif