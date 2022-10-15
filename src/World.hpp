#ifndef MY_WORLD_CLASS
#define MY_WORLD_CLASS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include <SFML/System.hpp>

#include "Map.hpp"
#include "containers/Chest.hpp"
#include "Floor.hpp"
#include "Object.hpp"

class World {
private:
    std::map <std::string, std::string> things_map {
        {"chest", "Chest"},
        {"floor", "Floor"},
    };

    std::vector <std::unique_ptr<Obj>> all_things;
    static std::unique_ptr<Obj> use_constructor(std::string name, std::pair<unsigned int, unsigned int> position);

public:
    World(/* args */) = default;
    World(std::vector <std::unique_ptr<Obj>> things) {
        // this->all_things = things;
    }
    World(const std::string & file_name) {
        std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
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
            this->all_things.push_back(use_constructor(name, position));
        }

        file.close();
    }
    ~World() = default;

    static std::vector <std::unique_ptr<Obj>> load_things_from_file(const std::string & file_name);
    void interraction(sf::Event & event);
    void iterate();
    Map create_map() const;
};

#endif