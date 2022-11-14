#ifndef MY_GAME_WORLD_CLASS
#define MY_GAME_WORLD_CLASS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <SFML/System.hpp>

// #include "Map.hpp"
#include "containers/Chest.hpp"
#include "environment/Wall.hpp"
#include "environment/Door.hpp"
#include "environment/Floor.hpp"
#include "alive_obj/Character.hpp"
#include "alive_obj/NPC.hpp"
#include "constants.hpp"

#include "vector.hpp"
#include "World_old.hpp"

template <>
class World<GameTypeSystem> {
public:
    enum GameMode {
        RUN,
        STOP,
        MENU,
        BACKPACK_MENU,
    };
private:
    struct Env {
        std::vector <std::shared_ptr<Wall>*>  walls;
        std::vector <std::shared_ptr<Floor>*> floor;
        my_stl::vector <std::shared_ptr<Door>*>  doors;
    };

    Character hero = Character(*this);
    Env env;

    size_t W, H;

    std::vector <std::shared_ptr<Obj<TypeSystem>>> all_things;
    std::vector <std::shared_ptr<NPC>> all_npc;
    std::vector <std::shared_ptr<Effect>> all_effects;
    std::map<TypeSystem, TextureStore> effects_textures;

    GameMode mode = RUN;
public:
    static std::shared_ptr<Obj<TypeSystem>> load_object(std::string name, std::ifstream & file);
    static std::shared_ptr<NPC> load_npc(std::string type, std::ifstream & file);
    TextureStore & get_effect_texture(TypeSystem type)
    { return effects_textures[type]; }
    const std::map<TypeSystem, TextureStore> & get_texture_store() const {
        return effects_textures;
    }

    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    const Character & get_hero() const { return hero; }
    const std::vector <std::shared_ptr<Obj<TypeSystem>>> & get_all_things() const { return all_things; }
    const std::vector <std::shared_ptr<NPC>> & get_all_npcs() const { return all_npc; }
    const std::vector <std::shared_ptr<Effect>> & get_all_effects() const { return all_effects; }
    
    const Env & get_env() const { return env; }

    static std::vector <std::shared_ptr<Obj<TypeSystem>>> load_things_from_file(const std::string & file_name);
    static std::vector <std::shared_ptr<NPC>> load_npcs_from_file(const std::string & file_name);
    static std::map<TypeSystem, TextureStore> load_effects_from_file(const std::string & file_name);

    World() : W(sf::VideoMode::getDesktopMode().size.x), H(sf::VideoMode::getDesktopMode().size.y) {}
    World(std::vector <std::shared_ptr<Obj<TypeSystem>>> things);
    World(const std::string & file_name);
    ~World() = default;

    void add_things_from_file(const std::string & file_name);
    void add_npcs_from_file(const std::string & file_name);
    void add_effects_from_file(const std::string & file_name);
    void add_character(const std::string & file_name);
    void add_effect(std::shared_ptr<Effect> effect) {
        all_effects.push_back(effect);
    }

    void interraction(sf::Event & event, sf::RenderWindow & window);
    void iterate();
    GameMode get_game_mode()
    { return mode; }

    void game_interraction(sf::Event & event, sf::RenderWindow & window);
    void menu_interraction(sf::Event & event, sf::RenderWindow & window);
    void backpack_menu_interraction(sf::Event & event, sf::RenderWindow & window);
};

#endif