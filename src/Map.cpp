#include "Map.hpp"

Map::Map(const World<GameTypeSystem> & w) : hero(w.get_hero()), W(w.get_W()), H(w.get_H()) {
    const std::vector <std::shared_ptr<Obj<GameTypeSystem>>> & at = w.get_all_things();
    // std::cout << "map_hero_position: (" << hero.get_position().first << ", " << hero.get_position().second << ")\n";
    const pair_ui64_t h_p = hero.get_position();
    for (size_t i = 0, l = at.size(); i < l; ++i) {
        pair_ui64_t p = at[i]->get_position();
        if (distance(p, h_p) <= 1900) {
            all_things.push_back((std::shared_ptr<Obj<GameTypeSystem>> *) &at[i]);
            // const sf::Sprite & hero_s = hero.get_sprite();
            const sf::Vector2f hero_pos = sf::Vector2f((float) h_p.first, (float) h_p.second);
            sf::Vector2f s_window_pos = sf::Vector2f((float)p.first, (float)p.second);
            s_window_pos.x = W/2 - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = H/2 - (hero_pos.y - s_window_pos.y);
            at[i]->set_sprite_position((pair_ui64_t) std::make_pair(s_window_pos.x, s_window_pos.y));

            // std::cout << "hero: (" << hero_pos.x << "; " << hero_pos.y << "); ";
            // std::cout << "map: (" << W << "; " << H << "); ";
            // std::cout << "s_w: (" << s_window_pos.x << "; " << s_window_pos.y << ");\n";
            
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
    for (size_t i = 0, l = npc.size(); i < l; ++i) {
        pair_ui64_t p = npc[i]->get_position();
        if (distance(p, h_p) <= 1900) {
            all_npc.push_back((std::shared_ptr<NPC>) npc[i]);
            // const sf::Sprite & hero_s = hero.get_sprite();
            const sf::Vector2f hero_pos = sf::Vector2f((float) h_p.first, (float) h_p.second);
            sf::Vector2f s_window_pos = sf::Vector2f((float)p.first, (float)p.second);
            s_window_pos.x = W/2 - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = H/2 - (hero_pos.y - s_window_pos.y);
            npc[i]->set_sprite_position((pair_ui64_t) std::make_pair(s_window_pos.x, s_window_pos.y));
        }
    }
    
    const std::vector <std::shared_ptr<Effect>> & eff = w.get_all_effects();
    for (size_t i = 0, l = eff.size(); i < l; ++i) {
        pair_ui64_t p = eff[i]->get_position();
        if (distance(p, h_p) <= 1900) {
            // const sf::Vector2f hero_pos = sf::Vector2f((float) h_p.first, (float) h_p.second);
            sf::Vector2 s_window_pos = sf::Vector2(p.first, p.second);
            s_window_pos.x = (W - eff[i]->get_texture()->getSize().x)/2; // - (hero_pos.x - s_window_pos.x);
            s_window_pos.y = (H - eff[i]->get_texture()->getSize().y)/2; // - (hero_pos.y - s_window_pos.y);
            eff[i]->set_sprite_position((pair_ui64_t) std::make_pair(s_window_pos.x, s_window_pos.y));
            // std::cout << "effect sprite position: (" << eff[i]->get_sprite().getPosition().x << ", " << eff[i]->get_sprite().getPosition().y << ")\n";
    
            all_effects.push_back(eff[i]);
        }
    }
}