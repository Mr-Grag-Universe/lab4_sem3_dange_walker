#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include <algorithm>
#include <vector>

#include "environment/environment.hpp"
#include "World.hpp"
#include "constants.hpp"
#include "alive_obj/Character.hpp"
#include "sfml_classes/sfml_object.hpp"

/**
 * @brief фактически объект сборщик для рендеринга. выбирает объекты из мира, которые в поле видимости
 *        и пережёвывает их в графические объекты для отрисовки
 */
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
    Map(World & w);
    Map(Map & m);
    ~Map() = default;

    //============= getters ============//

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

    //=========== other methods ===========//

    void update();

    template <typename Type>
    void process(std::shared_ptr<Type> obj, std::map<GameTypeSystem, ObjTextureStore> & ts, const sf::Vector2f h_p, pair_ui64_t p);

protected:
    struct Env {
        std::vector <std::shared_ptr<Wall> *> walls;
        std::vector <std::shared_ptr<Floor> *> floor;
        std::vector <std::shared_ptr<Door> * > doors;
    };    

private:
    // Env env;
};


template <typename Type>
void Map::process(std::shared_ptr<Type> obj, std::map<GameTypeSystem, ObjTextureStore> & ts, const sf::Vector2f hero_pos, pair_ui64_t p) {
    // all_things.push_back((std::shared_ptr<Type> *) &obj[i]);

    auto type = obj->get_type();
    size_t phase = obj->get_phase();
    std::shared_ptr<sf::Texture> t = ts[type].textures[phase];

    all_objs.push_back(std::make_shared<SFMLObject>(obj, ts[type], obj->get_layer()));
    all_objs.back()->set_texture(t, obj->get_size());
    
    sf::Vector2f window_pos = sf::Vector2f((float)p.first, (float)p.second);
    window_pos.x = W/2 - (hero_pos.x - window_pos.x);
    window_pos.y = H/2 - (hero_pos.y - window_pos.y);
    all_objs.back()->set_sprite_position((pair_ui64_t) std::make_pair(window_pos.x, window_pos.y));

    // all_objs.back()->set_life_time(ts[type].standard_life_time);
    // all_objs.back()->set_period(ts[type].standard_period);
    // all_objs.back()->correct_phase();
    // all_objs.back()->update_texture();
    // all_objs.back()->set_texture(ts[type].textures[obj->get_phase()], obj->get_size());
}

#endif