#ifndef MY_WORLD_CLASS
#define MY_WORLD_CLASS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

#include <SFML/System.hpp>

#include "containers/Chest.hpp"
#include "environment.hpp"
#include "alive.hpp"
#include "constants.hpp"
#include "sfml_classes/sfml_common.hpp"
#include "enums/Keys.hpp"
#include "events/event.hpp"

#include "my_stl_containers/include/vector.hpp"

static const std::set<GameTypeSystem> alive_types = { CHARACTER, SLIME, SKELETON, SIDOROVICH };
static const std::set<GameTypeSystem> effect_types = { MW_WAVE };

/**
 * @brief главный класс всей игры. здесь собраны все игровые объекты, загрузчики, обработчики и итераторы
 *  фактически это сердце программы. возможно стоило разгрузить этот склад, но я не усел бы. да и по хорошему много чего изначально надо было делать подругому
 *  так что имеем что имеем
 * 
 */
class World {
public:
    /// @brief состояние игры
    enum GameMode {
        RUN,
        STOP,
        MENU,
        BACKPACK_MENU,
        MESSAGE,
    };
private:
    bool GameOver_flag = false;
    /// @brief  склад объектов окружения (карты) - пол, стены, двери. по сути бесполезна
    struct Env {
        std::vector <std::shared_ptr<Wall>*>  walls;
        std::vector <std::shared_ptr<Floor>*> floor;
        my_stl::vector <std::shared_ptr<Door>*>  doors;
    };

    std::shared_ptr<Character> hero = std::make_shared<Character>(*this);
    Env env;

    size_t W, H;

    std::vector <std::shared_ptr<GameObj>> all_things = {};
    std::vector <std::shared_ptr<NPC>> all_npc;
    std::vector <std::shared_ptr<Effect>> all_effects;

    // хранилище всех тектур и стандартных таймингов для каждого типа объекта
    std::map<GameTypeSystem, ObjTextureStore> game_obj_textures;

    std::vector <std::shared_ptr<sf::Sound>> all_sounds;

    std::queue <std::shared_ptr<Event>> events;

    GameMode mode = RUN;

    std::queue<std::string> messages;
public:
    // для движения персонажа в нескольких направлениях одновременно
    std::map<std::string, KeyCondition> wasd = {
        {"W", RELEASED},
        {"S", RELEASED},
        {"A", RELEASED},
        {"D", RELEASED},
    };
    static std::shared_ptr<GameObj> load_object(std::string name, std::ifstream & file);
    static std::shared_ptr<NPC> load_npc(std::string type, std::ifstream & file);

    static std::vector <std::shared_ptr<GameObj>> load_things_from_file(const std::string & file_name);
    static std::vector <std::shared_ptr<NPC>> load_npcs_from_file(const std::string & file_name);
    static std::map<GameTypeSystem, ObjTextureStore> load_game_obj_textures_from_file(const std::string & file_name);

    World() : W(sf::VideoMode::getDesktopMode().size.x), H(sf::VideoMode::getDesktopMode().size.y) {}
    World(std::vector <std::shared_ptr<GameObj>> things);
    World(const std::string & file_name);
    ~World() = default;

    void add_things_from_file(const std::string & file_name);
    void add_npcs_from_file(const std::string & file_name);
    void add_effects_from_file(const std::string & file_name);
    void add_game_obj_textures_from_file(const std::string & file_name);
    void add_character(const std::string & file_name);
    void add_effect(std::shared_ptr<Effect> effect) {
        all_effects.push_back(effect);
    }

    void interraction(sf::Event & event, sf::RenderWindow & window);
    void iterate();

    // interraction
    void game_interraction(sf::Event & event, sf::RenderWindow & window);
    void menu_interraction(sf::Event & event, sf::RenderWindow & window);
    void backpack_menu_interraction(sf::Event & event, sf::RenderWindow & window);
    void message_menu_interraction(sf::Event & event, sf::RenderWindow & window);

    void use_the_nearest_thing();

    void push_sound(std::shared_ptr<sf:: Sound> sound) {
        all_sounds.push_back(sound);
    }
    void push_message(std::string message)
    { messages.push(message); }

    //============== getters =============//

    GameMode get_game_mode()
    { return mode; }

    const std::queue <std::shared_ptr<Event>> & get_events() const { return events; }
          std::queue <std::shared_ptr<Event>> & get_events()       { return events; }

    size_t get_W() const { return W; }
    size_t get_H() const { return H; }

    const Character &           get_hero() const    { return *hero; }
    Character &                 get_hero()          { return *hero; }
    std::shared_ptr<Character>  get_hero_ptr()      { return hero;  }
    
    const std::vector <std::shared_ptr<GameObj>> &  get_all_things()    const { return all_things;  }
    const std::vector <std::shared_ptr<NPC>>     &  get_all_npcs()      const { return all_npc;     }
    const std::vector <std::shared_ptr<Effect>>  &  get_all_effects()   const { return all_effects; }

    ObjTextureStore & get_obj_textures(GameTypeSystem type)
    { return game_obj_textures[type]; }

    std::map<GameTypeSystem, ObjTextureStore> & get_texture_store()       { return game_obj_textures; }
    std::map<GameTypeSystem, ObjTextureStore>   get_texture_store() const { return game_obj_textures; }

    const Env & get_env() const { return env; }

    const std::queue<std::string> & get_messages() const { return messages; }
          std::queue<std::string> & get_messages()       { return messages; }
    
    bool GameOver() const
    { return GameOver_flag; }

    //================= setters ================//

    void set_GameOver()
    { GameOver_flag = true; }
};

#endif