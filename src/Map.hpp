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
#include "sfml_classes/sfml_object.hpp"

class Map {
private:
    std::shared_ptr<Character> hero;
    const size_t W, H;
    std::vector <std::shared_ptr<GameObj> *> all_things;
    std::vector <std::shared_ptr<NPC>> all_npc;
    std::vector <std::shared_ptr<Effect>> all_effects;
    std::vector <std::shared_ptr<SFMLObject>> all_objs;
    std::map<GameTypeSystem, ObjTextureStore> ts;
    std::vector <std::shared_ptr<sf::Sound>> all_sounds;
public:
    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    const std::vector <std::shared_ptr<GameObj> *> & get_all_things() const 
    { return all_things; }
    const std::vector <std::shared_ptr<NPC>> & get_all_npcs() const 
    { return all_npc; }
    const std::vector <std::shared_ptr<Effect>> & get_all_effects() const 
    { return all_effects; }
    std::shared_ptr<Character> get_hero()
    { return hero; }
    const std::vector <std::shared_ptr<SFMLObject>> & get_all_objs() const
    {return all_objs; }

    Map(World & w);
    Map(Map & m);
    ~Map() = default;

    void update();
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