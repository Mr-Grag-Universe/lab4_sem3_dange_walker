#include "Map.hpp"

Map::Map(World & w) : hero(w.get_hero()), W(w.get_W()), H(w.get_H()) {
    const std::vector <std::shared_ptr<GameObj>> & at = w.get_all_things();
    std::map<GameTypeSystem, ObjTextureStore> & ts = w.get_texture_store();
    // const std::vector <std::shared_ptr<SFML_Object> & ao = w.get_all
    // std::cout << "map_hero_position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
    size_t g_ind = 0;
    std::shared_ptr<SFMLObject> obj;

    const pair_ui64_t h_p = hero.get_position();
    for (size_t i = 0, l = at.size(); i < l; ++i, ++g_ind) {
        pair_ui64_t p = at[i]->get_position();
        if (distance(p, h_p) <= 1900) {
            all_things.push_back((std::shared_ptr<GameObj> *) &at[i]);
            all_objs.push_back(std::make_shared<SFMLObject>(at[i], ts[at[i]->get_type()], at[i]->get_layer()));
            std::shared_ptr<sf::Texture> t = ts[at[i]->get_type()].textures[at[i]->get_phase()];
            all_objs[g_ind]->set_texture(t, at[i]->get_size());
            // const sf::Sprite & hero_s = hero.get_sprite();
            const sf::Vector2f hero_pos = sf::Vector2f((float) h_p.first, (float) h_p.second);
            sf::Vector2f s_window_pos = sf::Vector2f((float)p.first, (float)p.second);
            s_window_pos.x = W/2 - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = H/2 - (hero_pos.y - s_window_pos.y);
            // at[i]->set_sprite_position((pair_ui64_t) std::make_pair(s_window_pos.x, s_window_pos.y));
            all_objs[g_ind]->set_sprite_position((pair_ui64_t) std::make_pair(s_window_pos.x, s_window_pos.y));
            
            switch (at[i]->get_type()) {
                case FLOOR:
                    env.floor.push_back((std::shared_ptr<Floor> *) &at[i]);
                    break;
                case DOOR:
                    env.doors.push_back((std::shared_ptr<Door> *) &at[i]);
                    break;
                case WALL:
                    env.walls.push_back((std::shared_ptr<Wall> *) &at[i]);
                    break;
                default:
                    break;
            }
        }
    }
    
    const std::vector <std::shared_ptr<NPC>> & npc = w.get_all_npcs();
    for (size_t i = 0, l = npc.size(); i < l; ++i, ++g_ind) {
        pair_ui64_t p = npc[i]->get_position();
        if (distance(p, h_p) <= 1900) {
            GameTypeSystem obj_type = npc[i]->get_type();
            all_npc.push_back((std::shared_ptr<NPC>) npc[i]);
            obj = std::make_shared<SFMLObject>(npc[i], ts[obj_type], npc[i]->get_layer());
            obj->get_obj()->set_number_of_phases(ts[obj_type].textures.size());

            all_objs.push_back(obj);
            all_objs[g_ind]->set_period(ts[obj_type].standard_period);
            all_objs[g_ind]->correct_phase();
            all_objs[g_ind]->update_texture();
            [[maybe_unused]]size_t ph = all_objs[g_ind]->get_obj()->get_phase();
            std::shared_ptr<SFMLObject> o = all_objs[g_ind];

            all_objs[g_ind]->set_texture(ts[obj_type].textures[npc[i]->get_phase()], npc[i]->get_size());
            const sf::Vector2f hero_pos = sf::Vector2f((float) h_p.first, (float) h_p.second);
            sf::Vector2f s_window_pos = sf::Vector2f((float)p.first, (float)p.second);
            s_window_pos.x = W/2 - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = H/2 - (hero_pos.y - s_window_pos.y);
            all_objs[g_ind]->set_sprite_position(calculate_sprite_position(npc[i]->get_size(), (pair_ui64_t) std::make_pair(s_window_pos.x, s_window_pos.y)));
        }
    }
    
    const std::vector <std::shared_ptr<Effect>> & eff = w.get_all_effects();
    for (size_t i = 0, l = eff.size(); i < l; ++i, ++g_ind) {
        pair_ui64_t p = eff[i]->get_position();
        if (distance(p, h_p) <= 1900) {
            obj = std::make_shared<SFMLObject>(eff[i], ts[eff[i]->get_type()], eff[i]->get_layer());
            all_objs.push_back(obj);
            all_objs[g_ind]->set_life_time(ts[eff[i]->get_type()].standard_life_time);
            all_objs[g_ind]->set_period(ts[eff[i]->get_type()].standard_period);
            all_objs[g_ind]->correct_phase();

            all_objs[g_ind]->update_texture();
            all_objs[g_ind]->set_texture(ts[eff[i]->get_type()].textures[eff[i]->get_phase()], eff[i]->get_size());
            sf::Vector2 s_window_pos = sf::Vector2(p.first, p.second);
            all_objs[g_ind]->set_sprite_position(calculate_sprite_position(eff[i]->get_size(), (pair_ui64_t) std::make_pair(W/2, H/2)));
    
            all_effects.push_back(eff[i]);
        }
    }

    all_objs.push_back(std::make_shared<SFMLObject>(std::dynamic_pointer_cast<GameObj>(std::make_shared<Character>(hero)), ts[CHARACTER], 0));
    all_objs[all_objs.size()-1]->set_texture(ts[CHARACTER].textures[0], hero.get_size());
    all_objs[all_objs.size()-1]->set_sprite_position(calculate_sprite_position(hero.get_size(), std::make_pair(w.get_W()/2, w.get_H()/2)));

    // обработка звуковых очередей
    for (size_t i = 0; i < g_ind; ++i) {
        obj = all_objs[i];
        GameTypeSystem o_t = obj->get_obj()->get_type();
        std::vector <std::shared_ptr<sf::SoundBuffer>> sb = ts[o_t].sounds;
        if (sb.size()) {
            std::vector <std::shared_ptr<sf::Sound>> s = all_objs[i]->create_sounds(sb);
            for (const auto & _s: s) {
                w.push_sound(_s);
                _s->play();
            }
            // all_objs[i]->set_sounds(sb);
            // all_objs[i]->process_sound_queue();
        }
    }
}