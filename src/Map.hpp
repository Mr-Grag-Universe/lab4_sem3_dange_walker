#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include <algorithm>
#include <vector>

#include "environment/Wall.hpp"
#include "environment/Floor.hpp"
#include "environment/Door.hpp"
#include "World.hpp"
#include "constants.hpp"
#include "alive_obj/Character.hpp"

class Map {
private:
    const Character & hero;
    const size_t W, H;
    std::vector <std::unique_ptr<Obj> *> all_things;
public:
    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    const std::vector <std::unique_ptr<Obj> *> & get_all_things() const 
    { return all_things; }
    const Character & get_hero() const
    { return hero; }

    Map(const World & w);
    Map(const Map & m) = default;
    ~Map() = default;
protected:
    struct Env {
        std::vector <std::unique_ptr<Wall> *> walls;
        std::vector <std::unique_ptr<Floor> *> floor;
        std::vector <std::unique_ptr<Door> * > doors;
    };    

private:
    Env env;
};

#endif