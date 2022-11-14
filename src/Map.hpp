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
    std::vector <std::shared_ptr<Obj<GameTypeSystem>> *> all_things;
    std::vector <std::shared_ptr<NPC>> all_npc;
    std::vector <std::shared_ptr<Effect>> all_effects;
public:
    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    const std::vector <std::shared_ptr<Obj<GameTypeSystem>> *> & get_all_things() const 
    { return all_things; }
    const std::vector <std::shared_ptr<NPC>> & get_all_npcs() const 
    { return all_npc; }
    const std::vector <std::shared_ptr<Effect>> & get_all_effects() const 
    { return all_effects; }
    const Character & get_hero() const
    { return hero; }

    Map(const World & w);
    Map(const Map & m) = default;
    ~Map() = default;
protected:
    struct Env {
        std::vector <std::shared_ptr<Wall> *> walls;
        std::vector <std::shared_ptr<Floor> *> floor;
        std::vector <std::shared_ptr<Door> * > doors;
    };    

private:
    Env env;
};

#endif